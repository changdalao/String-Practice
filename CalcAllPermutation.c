void Reverse(char* s, int from, int to) {
    while (from<to) {
                char tmp = s[from];
                s[from++] = s[to];
                s[to--] = tmp;
    }
}
void CalcAllPermutation1(char* str,int len)
{
    int i=0;
    for(i=len-2;i>=0 && str[i]>str[i+1];i--)//最后一个升序的位置
    {
        ;
    }
    if(i<0)
        return;
    //找到适当位置,找比他大的最小数字
    int k=len-1;
    for(k=len-1;(k>i)&&(str[k]<=str[i]);--k){//i后面比他大的最小数字
        ;
    }
    //找到适当位置k
    swap(&str[i],&str[k]);
    Reverse(str,i+1,len-1);
}
int main()
{
    char str[]="21543";
    CalcAllPermutation1(str1,5);
    printf("%s\n",str1);
    return 0;
}
