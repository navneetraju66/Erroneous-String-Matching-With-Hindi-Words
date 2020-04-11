#include<stdio.h>
#include<string.h>
#include<glib.h>
#include<locale.h>

//to run this code 1) gcc filename.c -o filename `pkg-config --libs --cflags gtk+-3.0`
//then run 2)./filename

#include <wchar.h>
#define THRESHOLD 3
int editDistDP(wchar_t *str1, wchar_t *str2);
int getWords(wchar_t *base, wchar_t target[100][100])
{
	int n=0,i,j=0;
	
	for(i=0;TRUE;i++)
	{
		if(base[i]!=' '){
			target[n][j++]=base[i];
		}
		else{
			target[n][j++]='\0';//insert NULL
			n++;
			j=0;
		}
		if(base[i]=='\0')
		    break;
	}
	return n;
	
}

int main()
{
	//word to be looked for-mention here
	wchar_t a[] =L"नमसन";

	//setlocale(LC_ALL, "en_US.utf16");
	//your input sentence
	wchar_t b[]=L"नमस्ते यह एक परीक्षण वाक्य है जो मैंने बनाया है इसमें नमस्ते शब्द है";
    //printf("%d %d\n",a[4],b[4]);
    //wprintf(L"%lc\n",a);
	//printf("%ld\n",wcslen(b));
	//wprintf(L"2 %ls \n",a);
	//wchar_t str[80]; 
    //int i; 
    
    
    wchar_t arr[100][100];
    int n=getWords(b,arr);
    setlocale(LC_ALL, "");
    wprintf(L"2 %ls \n",b);
    wprintf(L"2 %ls \n",arr[13]);
    int no;
    for(int i=0;i<=n;i++)
    {
        no=editDistDP(a,arr[i]);
        if(no<=THRESHOLD)
            //printf("Word:%d\n",i);
            wprintf(L"2 %ls %d\n",arr[i],i);
    }
    //printf("words:%d\n",n);
    
    //scanf("%ls", str);
    if(a[0]==a[3])
    { 
    //printf("%ld",wcslen(a));
	}

	//int no;
	//no=editDistDP(a,b);
	//printf("%d\n",no);
	

}

int min1(int x,int y)
{
	if(x<y)
		return x;
	else
		return y;
}

int min(int x, int y, int z) 
{ 
   return min1(min1(x, y), z); 
}

int editDistDP(wchar_t *str1, wchar_t *str2) 
{ 
    // Create a table to store results of subproblems 
    int m;
    int n;
    m=wcslen(str1);
    n=wcslen(str2);
    int dp[m+1][n+1]; 
  
    // Fill d[][] in bottom up manner 
    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
            // If first string is empty, only option is to 
            // insert all characters of second string 
            if (i==0) 
                dp[i][j] = j;  // Min. operations = j 
  
            // If second string is empty, only option is to 
            // remove all characters of second string 
            else if (j==0) 
                dp[i][j] = i; // Min. operations = i 
  
            // If last characters are same, ignore last char 
            // and recur for remaining string 
            else if (str1[i-1] == str2[j-1]) 
                dp[i][j] = dp[i-1][j-1]; 
  
            // If the last character is different, consider all 
            // possibilities and find the minimum 
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert 
                                   dp[i-1][j],  // Remove 
                                   dp[i-1][j-1]); // Replace 
        } 
    } 
  
    return dp[m][n];
}
