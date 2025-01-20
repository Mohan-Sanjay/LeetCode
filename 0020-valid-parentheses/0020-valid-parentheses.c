
bool isValid(char* s) {
    int l=strlen(s);
    char stack[l];
    stack[0]=0;
    int top=-1;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='}' ||s[i]==']' ||s[i]==')')
        {  
            if(top==-1) return 0;
            if(stack[top]=='{' || stack[top]=='[' ||stack[top]=='(' )
            {
                if(s[i]-stack[top]==2 ||s[i]-stack[top]==1)
                    top--;
                else
                    stack[++top]=s[i];
            }
            else
                stack[++top]=s[i];
        }
        else
            stack[++top]=s[i];
    }
    return top==-1;
}