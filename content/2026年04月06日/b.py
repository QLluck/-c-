x = int(input())
f =1 ;
sum =0;
s=0;
n=0;
while(f):
    sum*=10
    sum=sum+1;
    # print(sum)
    if(sum%x==0):
        s=sum//x;
        
        num=0;
        while(sum):
            num=num+1;
            sum=sum//10;
            # print(sum)
        n=num
        break
# s=int(s)
print(f"{s} {n}");
    
