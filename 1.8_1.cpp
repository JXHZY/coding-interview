//  CODING INTERVIEW
//  1.8_1.cpp   自己把题目意思理解错了
//  Created by Ying Zhou on 15/6/2.
//  Copyright (c) 2015年 Ying Zhou. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int isSubtring(string s1, string s2)
{
    if(s1.length()!=s2.length())
    {
        return 0;
    }
    int index1 = 0;
    int index2 = 0;
    int find = 0;
    int result = 1;
    int keep;
    for(int i = 0; s1[i]!='\0';i++)
    {
        if(s2[0]==s1[i])
        {
            index1 = i;
            find = 1;
            break;
        }
    }
    keep = index1;
    if(find == 0)
    {
        return 0;
    }
    for(int i = 0; s2[i]!='\0';i++)
    {
        if(s2[i] == s1[index1])
        {
            index1++;
        }
        else
        {
            if(s1[index1]!='\0')
            {
                return 0;
            }
            index2 = i;
            break;
        }
    }
    for(int i = 0; s1[i]!='\0';i++)
    {
        if(s1[i]==s2[index2])
        {
            index2++;
        }
        else
        {
            if((s2[index2]=='\0')&&(i==keep))
            {
                result = 1;
                break;
            }
            if(i!=keep)
            {
                result = 0;
                break;
            }
        }
    }
    return result;
}//end isSubtring

int main()
{
    string s1,s2;
    int result;
    cout << "Please input the two string" <<endl;
    cin >> s1 >> s2;
    result = isSubtring(s1,s2);
    if(result == 1)
    {
        cout << "Success!!!!!" <<endl;
    }
    else
    {
        cout << "Failed!!!!!!" << endl;
    }
    return 0;
}//end main