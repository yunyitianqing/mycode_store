#include<stdio.h>

int main()
{
	unsigned char a;
	unsigned char b;
	unsigned char c;
	unsigned char d;
	unsigned char e;
	
	a=0xfe;
	b=c=d=e=0;
	printf("%d %d\n",a,b);
	scanf("%d",&e);
	a=0xff;
	printf("%d %d\n",a,b);
	for(int i=0;i<8;i++)
	{
		//printf("%x %x\n",a,b);
		if((e>>i)%2)
		{
			printf("a\n");
			if(b&0x01)
			{
				printf("a1\n");
				c|=1;
			}
			if(a&0x01)
			{
				printf("a2\n");
				d|=1;
			}
		}
		else
		{
			printf("b\n");
			if(a&0x01)
			{
				printf("b1\n");
				c|=1;
			}
			if(b&0x01)
			{
				printf("b2\n");
				d|=1;
			}
		}
		
		a>>=1;
		b>>=1;
		printf("%x %x\n",a,b);
		printf("%x %x\n",c,d);
		if(i!=7)
		{
			c<<=1;
			d<<=1;
		}
	}
	printf("%x %x\n",c,d);
	
	return 0;
}
