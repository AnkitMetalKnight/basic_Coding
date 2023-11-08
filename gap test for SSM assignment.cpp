#include <stdio.h>
#include <iostream>
#include <string>
#include<unordered_map>
#include<limits.h>
#include <iomanip>
#include <math.h>
 
using namespace std;

void gap_finder(const std::string& str)
{
    float n = str.size();

    n-=10;
    float dAlpha = 1.36/sqrt(n);
    unordered_map<int, int> freqMap;
    int a =0;
    int maxm = INT_MIN;
    
    for (int i = 0; i <= 9; i++) {
        printf("For %d: ", i);
        int d = 0;
        int no_of_gaps = 0;
        int no_ocr = 0;
        bool flag = false;
        for (char j : str) 
        {
            if (j == std::to_string(i).at(0)) 
            {
                flag = true;
                no_ocr++;
                if (no_ocr > 1) 
                {
                    printf("%d, ", d);
                    freqMap[d]++;
                    maxm = max(maxm, d);
                    no_of_gaps++;
                }
                d = 0;
            } 
            else if (flag==true) 
                {
                    d++;
                }
        }
        printf("No. of Gaps = %d\n", no_of_gaps);
            
    }
    int loop_cnt = 0;
    for(int i =0 ;i<=maxm; i+=4)
    {
        int j = i ;
        int sum = 0 ;
        int count=0;
        while(count!=4)
        {
            sum+=freqMap[j++];
            count++;
        }
        loop_cnt++;
        
        count = 0;
    }
    
    float rel_freq[loop_cnt] ={0};
    float acc_rel_freq[loop_cnt];
    float Fx[loop_cnt];
    float diff[loop_cnt];
    float D = INT_MIN;
    
    int k = 0;
    for(int i =0 ;i<=maxm; i+=4)
    {
        int j = i ;
        float sum = 0 ;
        int count=0;
        while(count!=4)
        {
            sum+=freqMap[j++];
            count++;
        }
        
        rel_freq[k] = sum/n;
        acc_rel_freq[k] = acc_rel_freq[k-1] + rel_freq[k];
        Fx[k] = 1 - pow(0.9, i+count);
        diff[k] = abs(Fx[k] - acc_rel_freq[k]);
        D = max(diff[k],D);
        k++;
        count = 0;
    }
    cout<<"Relative Frequency\t"<<"Actual Relative Frequency\t"<<"F(x)\t\t"<<"|F(x)-S(x)|\n";
    for(int i = 0;i<loop_cnt;i++)
    {
            cout<<rel_freq[i]<<std::setw(30) <<acc_rel_freq[i]<<std::setw(25)<<Fx[i]<<std::setw(15)<<diff[i]<<"\n";
        
    }
    
    cout<<"D value we got is: "<<D<<"\n"<<"And D_Alpha value: "<<dAlpha<<endl;
    if(D<dAlpha)
    cout<<"Since D = max |F(x) - SN(x)|is less than D0.05, do not reject the hypothesis of independence on the basis of this test.";
    else
    cout<<"Since D = max |F(x) - SN(x)| is more than D0.05, reject the hypothesis of independence on the basis of this test.";

}

int main(){

// string st;
//     cout<<"Enter numbers of your choice\n";
//     cin>>st;
//     gap_finder(st);
    gap_finder("45579044759542390");
    return 0;
}
