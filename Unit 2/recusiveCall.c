/* tail recursive call
int fact(int n)
{
    if(n==1)
        return n;
    return n*fact(n-1);
} 
*/

/*
non-tail recursive call
int fact(int n,int a)
{
    if(n==1)
        return a;
    return fact(n-1,n*a);
}
*/