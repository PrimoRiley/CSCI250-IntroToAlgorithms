/* 
This program was made for algorithm comparison purposes. The following code is
largely taken from Geeks for Geeks and is not entirely my own. My implementation 
of Horspool's algorithm can be found in the respository under Assignment 3.  
*/

#include <bits/stdc++.h>
using namespace std;
# define NO_OF_CHARS 256
 
// The preprocessing function for Boyer Moore's
// bad character heuristic
void badCharHeuristic( string str, int size,
                        int badchar[NO_OF_CHARS])
{
    int i;
 
    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
 
    // Fill the actual value of last occurrence
    // of a character
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;

    cout<<badchar[116]<<endl;
}
 
/* A pattern searching function that uses Bad
Character Heuristic of Boyer Moore Algorithm */
int search( string txt, string pat)
{
    int occurances = 0;
    //start timer for reading file
    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    int m = pat.size();
    int n = txt.size();
 
    int badchar[NO_OF_CHARS];
 
    /* Fill the bad character array by calling
    the preprocessing function badCharHeuristic()
    for given pattern */
    badCharHeuristic(pat, m, badchar);
 
    int s = 0; // s is shift of the pattern with
                // respect to text
    while(s <= (n - m))
    {
        int j = m - 1;
 
        /* Keep reducing index j of pattern while
        characters of pattern and text are
        matching at this shift s */
        while(j >= 0 && pat[j] == txt[s + j])
            j--;
 
        /* If the pattern is present at current
        shift, then index j will become -1 after
        the above loop */
        if (j < 0)
        {
            //cout << "pattern occurs at shift = " <<  s << endl;
            occurances++;
            /* Shift the pattern so that the next
            character in text aligns with the last
            occurrence of it in pattern.
            The condition s+m < n is necessary for
            the case when pattern occurs at the end
            of text */
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;
 
        }
 
        else
            /* Shift the pattern so that the bad character
            in text aligns with the last occurrence of
            it in pattern. The max function is used to
            make sure that we get a positive shift.
            We may get a negative shift if the last
            occurrence of bad character in pattern
            is on the right side of the current
            character. */
            s += max(1, j - badchar[txt[s + j]]);
    }

    end = chrono::high_resolution_clock::now();     
    chrono::duration<double> elapsed_seconds = end - start;
    //ends timer

    cout<<"Time to read: "<<elapsed_seconds.count()<<endl<<endl;
    return occurances;
}
 
/* Driver code */
int main()
{   
    ifstream ifs("Text.txt");
    //Two ways:
  
    //Assign it at initialization
    string content( (istreambuf_iterator<char>(ifs) ),
                  (istreambuf_iterator<char>()    ) );
  
    string txt= "TTATAGATCTCGTATTCTTTTATAGATCTCCTATTCTT";
    string pat = "10001";
    cout<<"Occurances: "<<search(content, pat)<<endl;
    return 0;
}
  