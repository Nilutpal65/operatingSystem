#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

main()
{
        pid_t pid ;
        int x = 5,i ;
        pid = fork();
        x++;
        if( pid == -1  )
        {
                printf("Process creation unsuccessful\n") ;
                exit(-1);
        }
        else if( pid > 0 )
        {
		wait();
                printf("Parent starts\n") ;
		for( i = 0 ; i<= 10 ; ++i  ) if(!(i&1))
		printf("%d\t",i);
		printf("\n");
                printf("Parent ends\n") ;
        }
        else if( pid == 0  )
	{
		printf("Child starts\n");
		for(i=1 ; i<=10 ;++i  ) if(i&1)
		printf("%d\t",i);
		printf("\n");
                printf("Child ends\n") ;

	}
}
