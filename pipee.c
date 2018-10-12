#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>


int main(){
	int array[1000];
	int sum10=0,sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0,sum7=0,sum8=0,sum9=0,sum=0;
	int fd1[2],fd2[2],fd3[2],fd4[2],fd5[2],fd6[2],fd7[2],fd8[2],fd9[2],fd10[2];
	for(int i=0;i<1000;i++){
		array[i]=i;
	}
	if(pipe(fd1)==-1){
		printf("Pipe failed 1\n");
		return 0;
	}
	if(pipe(fd2)==-1){
		printf("Pipe failed 2\n");
		return 0;
	}
	if(pipe(fd3)==-1){
		printf("Pipe failed 3\n");
		return 0;
	}
	if(pipe(fd4)==-1){
		printf("Pipe failed 4\n");
		return 0;
	}
	if(pipe(fd5)==-1){
		printf("Pipe failed 5\n");
		return 0;
	}
	if(pipe(fd6)==-1){
		printf("Pipe failed 6\n");
		return 0;
	}
	if(pipe(fd7)==-1){
		printf("Pipe failed 7\n");
		return 0;
	}
	if(pipe(fd8)==-1){
		printf("Pipe failed 8\n");
		return 0;
	}
	if(pipe(fd9)==-1){
		printf("Pipe failed 9\n");
		return 0;
	}
	if(pipe(fd10)==-1){
		printf("Pipe failed 10\n");
		return 0;
	}
	int cpid1=fork();
	if(cpid1==0){
		for(int i=0;i<100;i++){
			sum1+=array[i];
		}
		write(fd1[1], &sum1 ,sizeof(sum1));        
		close(fd1[1]);
     		exit(0);
	}
	else{
		int cpid2=fork();
		if(cpid2==0){
			for(int i=100;i<200;i++){
				sum2+=array[i];
			}
			write(fd2[1], &sum2,sizeof(sum2));
      			close(fd2[1]);
      			exit(0);
		}
		else{
			int cpid3=fork();
			if(cpid3==0){
				for(int i=200;i<300;i++){
					sum3+=array[i];
				}
				write(fd3[1],&sum3,sizeof(sum3));
      				close(fd3[1]);
      				exit(0);
			}
			else{
				int cpid4=fork();
				if(cpid4==0){
					for(int i=300;i<400;i++){
						sum4+=array[i];
					}
					write(fd4[1], &sum4,sizeof(sum4));
      					close(fd4[1]);
      					exit(0);
				}
				else{
					int cpid5=fork();
					if(cpid5==0){
						for(int i=400;i<500;i++){
							sum5+=array[i];
						}
						write(fd5[1],&sum5,sizeof(sum5));
      						close(fd5[1]);
      						exit(0);
					}
					else{
						int cpid6=fork();
						if(cpid6==0){
							for(int i=500;i<600;i++){
								sum6+=array[i];
							}
							write(fd6[1], &sum6,sizeof(sum6));
      							close(fd6[1]);
      							exit(0);
						}
						else{
							int cpid7=fork();
							if(cpid7==0){
								for(int i=600;i<700;i++){
									sum7+=array[i];
								}
								write(fd7[1], &sum7,sizeof(sum7));
      								close(fd7[1]);
      								exit(0);
							}
							else{
								int cpid8=fork();
								if(cpid8==0){
									for(int i=700;i<800;i++){
										sum8+=array[i];
									}
									write(fd8[1], &sum8,sizeof(sum8));
      									close(fd8[1]);
      									exit(0);
								}
								else{
									int cpid9=fork();
									if(cpid9==0){
										for(int i=800;i<900;i++){
											sum9+=array[i];
										}
										write(fd9[1], &sum9,sizeof(sum9));
      										close(fd9[1]);
      										exit(0);
									}
									else{
										for(int i=900;i<1000;i++){
											sum10+=array[i];
										}
										write(fd10[1], &sum10,sizeof(sum10));
      										close(fd10[1]);
      										wait(NULL);
									}wait(NULL);
								}wait(NULL);
							}wait(NULL);
						}wait(NULL);
					}wait(NULL);
				}wait(NULL);
			}wait(NULL);
		}wait(NULL);
	}
	read(fd1[0],&sum1,sizeof(int));
	read(fd2[0],&sum2,sizeof(int));
	read(fd3[0],&sum3,sizeof(int));
	read(fd4[0],&sum4,sizeof(int));
	read(fd5[0],&sum5,sizeof(int));
	read(fd6[0],&sum6,sizeof(int));
	read(fd7[0],&sum7,sizeof(int));
	read(fd8[0],&sum8,sizeof(int));
	read(fd9[0],&sum9,sizeof(int));
	read(fd10[0],&sum10,sizeof(int));
	sum = sum1+sum2+sum3+sum4+sum5+sum6+sum7+sum8+sum9+sum10;
	printf("Sum = %d",sum);
	printf("\n");
	close(fd1[0]);
	close(fd2[0]);
	close(fd3[0]);
	close(fd4[0]);
	close(fd5[0]);
	close(fd6[0]);
	close(fd7[0]);
	close(fd8[0]);
	close(fd9[0]);
	close(fd10[0]);
	return 0;
}
