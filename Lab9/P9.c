#include<stdio.h>
#include<stdlib.h>
void FIFO(char [ ],char [ ],int,int);
int lru();
int main()
{
	int ch,YN=1,i,l,f;
	char F[10],s[25];
	do
	{
		printf("\n\n\t*********** MENU ***********");
		printf("\n\n\t1:FIFO\n\n\t2:LRU \n\n\t3:EXIT");
		printf("\n\n\tEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n\n\tEnter the no of empty frames: "); 
				scanf("%d",&f);
				printf("\n\n\tEnter the length of the string: ");
				scanf("%d",&l);
				printf("\n\n\tEnter the string: ");
				scanf("%s", s);
				for(i=0;i<f;i++)
				F[i]=-1;
				FIFO(s,F,l,f);
				break;
			case 2:	lru();
				break;
			case 3: exit(0);
		}	
		printf("\n\n\tDo u want to continue IF YES PRESS 1\n\n\tIF NO PRESS 0 : "); 
		scanf("%d",&YN);
		}while(YN==1);
	return(0);
}
void FIFO(char s[],char F[],int l,int f)
{
	int i,j=0,k,flag=0,cnt=0;
	printf("\n\tPAGE\t	FRAMES\t                   FAULTS");
	for(i=0;i<l;i++)
	{
		for(k=0;k<f;k++)
		{
			if(F[k]==s[i])
			flag=1;
		}
		if(flag==0)
		{
			printf("\n\t%c\t",s[i]);
			F[j]=s[i];
			j++;
			for(k=0;k<f;k++)
			{
				printf("	%c",F[k]);
			}
			printf("\tPage-fault%d",cnt);
			cnt++;
		}
		else
		{
			flag=0;
			printf("\n\t%c\t",s[i]);
			for(k=0;k<f;k++)
			{
				printf("	%c",F[k]);
			}
			printf("\tNo page-fault");
		}
		if(j==f)
		j=0;
	}
}
int findLRU(int time[], int n)
{
	int i, minimum = time[0], pos = 0; 
	for(i = 1; i < n; ++i)
	{
	        if(time[i] < minimum)
		{
			minimum = time[i];
			pos = i;
	        }
	}
        return pos;
} 
int lru()
{
	int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
	printf("Enter number of frames: ");
	scanf("%d", &no_of_frames);  
	printf("Enter number of pages: ");
	scanf("%d", &no_of_pages);    
	printf("Enter reference string: ");    
	for(i = 0; i < no_of_pages; ++i)
	{
		scanf("%d", &pages[i]);
	}    
	for(i = 0; i < no_of_frames; ++i)
	{
		frames[i] = -1;
	}   
	for(i = 0; i < no_of_pages; ++i)
	{
		flag1 = flag2 = 0;        
		for(j = 0; j < no_of_frames; ++j)
		{
			if(frames[j] == pages[i])
			{
				counter++;
				time[j] = counter;
				flag1 = flag2 = 1;
				break;
			}
		}       
		if(flag1 == 0)
		{
			for(j = 0; j < no_of_frames; ++j)
			{
				if(frames[j] == -1)
				{
					counter++;
					faults++;
					frames[j] = pages[i];
					time[j] = counter;
					flag2 = 1;
					break;
				}
			}    
		}      
		if(flag2 == 0)
		{
			pos = findLRU(time, no_of_frames);
			counter++;
			faults++;
			frames[pos] = pages[i];
			time[pos] = counter;
		}       
		printf("\n");      
		for(j = 0; j < no_of_frames; ++j)
		{
			printf("%d\t", frames[j]);
		}
	}  
	printf("\n\nTotal Page Faults = %d", faults);    
	return 0;
}
