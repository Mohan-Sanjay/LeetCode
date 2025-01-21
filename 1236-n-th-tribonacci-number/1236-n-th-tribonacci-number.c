int tribonacci(int n) {
    int p1=0;
    int p2=1;
    int p3=1;
    int c=(n+1)/2;
    for(int i=2;i<n;i++)
    {
        c=p1+p2+p3;
        p1=p2;
        p2=p3;
        p3=c;
    }
    return c;
}