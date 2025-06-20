#include <stdio.h>
#include <string.h>

int main()
{
	char in[30], out[60];  
	int j = 0, count = 0;
	
	printf("Enter a string: ");
	scanf("%s", in);
	
	for(int i = 0; in[i] != '\0'; i++)
	{
		out[j++] = in[i];
		
		if(in[i] == '1')
		{
			count++;
			if(count == 5)
			{
				out[j++] = '0';  
				count = 0;       
			}
		}
		else
		{
			count = 0;  
		}
	}
	out[j] = '\0';  
	
	printf("Stuffed data is: %s\n", out);
	
	return 0;
}

