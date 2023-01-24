/*
Riley Primeau
primeauriley@gmail.com
testing
*/

#include<iostream>
#include<string>
#include<fstream>
#include<chrono>

using namespace std;

double* horspools(char*, const char*, int, int);
void hShiftTable(const char*, int, int*);

double* kmp(char*, const char*, int, int);
void kmpShift(const char*, int, int*);

double* karpRabin(char*, const char*, int, int);
int karpRabinHash(const char*, int, int);

//maximum number of characters that can be represented in extended ASCII is 256
int max_characters = 256;

int main()
{
    char response;
    cout<<"PATTERN SEARCHING"<<endl;
    cout<<"Press S to search or Q to quit"<<endl;
    cin>>response;

    string file;
    const char* filename;
    string patternInput;
    if(response == 'S')
    {
        cout<<"Please specify input file name"<<endl;
        getline(cin >> ws, file);
        cout<<"Please specify pattern to search for"<<endl;
        getline(cin >> ws, patternInput);
    }
    if(response == 'Q')
    {
        cout<<"Goodbye"<<endl;
        return 0;
    }
    cout<<endl;
    //create filename and pattern char arrays
    filename = file.c_str();
    int pSize = patternInput.length(); //pattern length
    const char* pattern = patternInput.c_str();

    //start timer for reading file
    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    ifstream is(filename, ifstream::binary);
    
    if(!is.good())
    {
        cout<<"Invalid Input"<<endl;
        return 0;
    }
        
    // get length of file:
    is.seekg (0, is.end);
    int tSize = is.tellg(); //text length
    is.seekg (0, is.beg);

    char * text = new char[tSize]; //allocate memory
    is.read(text,tSize);
    //cout.write (text,tSize); //print text
    is.close();

    end = chrono::high_resolution_clock::now();     
    chrono::duration<double> elapsed_seconds = end - start;
    //ends timer

    cout<<"Text read! Time to read: "<<elapsed_seconds.count()<<endl<<endl;

    double* hResults = horspools(text, pattern, tSize, pSize);
    cout<<"HORSPOOLS: Number of occurances in the text: "<<hResults[0]<<" - Number of comparisons: "<<hResults[1]<<" - Time: "<<hResults[2]<<endl;
    
    double* kmpResults = kmp(text, pattern, tSize, pSize);
    cout<<"KMP: Number of occurances in the text: "<<kmpResults[0]<<" - Number of comparisons: "<<kmpResults[1]<<" - Time: "<<kmpResults[2]<<endl;
   
    double* karpRabinResults = karpRabin(text, pattern, tSize, pSize);
    cout<<"KARP RABIN: Number of occurances in the text: "<<karpRabinResults[0]<<" - Number of comparisons: "<<karpRabinResults[1]<<" - Time: "<<karpRabinResults[2]<<endl;

   delete[] text;

}

double* horspools(char text[], const char pattern[], int tSize, int pSize)
{ 
    //starts horspools timer
    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    //creates and fills shift table
    int* shift = new int[256];
    hShiftTable(pattern, pSize, shift);
    
    //metrics to keep track of
    int occurances = 0; 
    int comparisons = 0;

    long i = 0; 
    while(i <= tSize - pSize)
    {
        //compares characters staring from back of pattern
        int j = pSize - 1;
        while(j >=0 && text[i + j] == pattern[j])
        {
            j--;
        }
        if(j<0) //match found
        {
            occurances++;
            //cout<<"Pattern found at index "<<i<<" in text."<<endl;
            if(i + pSize < tSize)
            {
                i += pSize - shift[(int)text[i+pSize]]; //shifts pattern
                i++;
            }
            else
            {
                i++;
            }

        }
        else
        {
            i += max(1, j - shift[(int)text[i + j]]); //shifts pattern either according to the shift table or by 1
            comparisons++;
        }
    }

    //end timer
    end = chrono::high_resolution_clock::now();    
    chrono::duration<double> elapsed_seconds = end - start;

    double* results = new double[3];
    results[0] = occurances;
    results[1] = comparisons;
    results[2] = elapsed_seconds.count();

    return results;
}

void hShiftTable(const char pattern[], int m, int shift[])
{
    //populate shift table (length - index - 1)
    for(int i = 0; i<max_characters; i++)
        shift[i] = m; //pattern length
    for(int i = 0; i<m - 1; i++)
        shift[(int)pattern[i]] = m - 1 - i;
}

double* kmp(char text[], const char pattern[], int tSize, int pSize)
{
    //start timer
    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    int shift[pSize];
    kmpShift(pattern, pSize, shift); //populate shift table
    
    int i = 0;
    int j = 0;
    int occurances = 0;
    int comparisons = 0;
       
    while(i < tSize)
    {
        //if characters match then increment each index
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if(j == pSize) //pattern is found cause j index is the size of the pattern
        {
            //cout<<"Pattern found at index: "<<i - j<<endl;
            occurances++;
            j = shift[j-1];
        }
        else if(i<tSize && pattern[j] != text[i]) //otherwise shift
        {
            comparisons++;
            if(j != 0)
                j = shift[j -1];
            else
                i++;
        }
    }

    //end timer
    end = chrono::high_resolution_clock::now();     
    chrono::duration<double> elapsed_seconds = end - start;
    
    double* results = new double[3];
    results[0] = occurances;
    results[1] = comparisons;
    results[2] = elapsed_seconds.count();

    return results;
}

void kmpShift(const char pattern[], int pSize, int shift[])
{
    int ffixLength = 0; //length of prefix/suffix
    shift[0] = 0;

    int i = 1;
    while(i<pSize)
    {
        if(pattern[i] == pattern[ffixLength])
        {
            ffixLength++;
            shift[i] = ffixLength;
            i++;
        }
        else if(ffixLength != 0)
            ffixLength = shift[ffixLength - 1];
        else
        {
            shift[i] = 0;
            i++;
        }
    }
}

double* karpRabin(char text[], const char pattern[], int tSize, int pSize)
{
    //start timer
    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    double comparisons = 0;
    double occurances = 0;

    int q = 13; //prime number for modulo
    int i, j;
    int pHash = 0; // hash value for pattern
    int tHash = 0; // hash value for text
    int h = 1;
 
    //h = d^(pSize - 1)
    for (i = 0; i < pSize - 1; i++)
        h = (h * max_characters) % q;
    
    // Calculate hashs
    pHash = karpRabinHash(pattern, pSize, q);
    tHash = karpRabinHash(text, pSize, q);
 
    for (i = 0; i <= tSize - pSize; i++) 
    {
        if (pHash == tHash) 
        {
            comparisons++;
            //check characters
            for (j = 0; j < pSize; j++) 
            {
                if (text[i + j] != pattern[j]) 
                    break;
            }
            if (j == pSize)
            {
                //cout<<"Pattern found at index: "<<i<< endl;
                occurances++;
            }      
        }
 
        if (i < tSize - pSize)
        {
            //calculates hash for next window (subtracts first term and adds new one)
            tHash = (max_characters * (tHash - text[i] * h) + text[i + pSize]) % q; 
            //ensures tHash is positive
            if (tHash < 0) 
                tHash = (tHash + q);
        }
    }

    //ends timer
    end = chrono::high_resolution_clock::now();     
    chrono::duration<double> elapsed_seconds = end - start;

    double* results = new double[3];
    results[0] = occurances;
    results[1] = comparisons;
    results[2] = elapsed_seconds.count();

    return results;
}

int karpRabinHash(const char text[], int pSize, int prime)
{
    int hash = 0;
    for (int i = 0; i < pSize; i++) {
        hash = (max_characters * hash + text[i]) % prime; //hash formula
    }
    return hash;
}





