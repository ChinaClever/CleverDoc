#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>




int main(void)

{
	int num,sum,port,ret;
	char ch;
	char str1[256]={'\0'};  //防止误选择
	char *ip,ipbuf1[3], ipbuf2[3],ipbuf3[3],ipbuf4[3]; //字符串IP
	int  ipnum1,ipnum2,ipnum3,ipnum4;
	char str2[512]={'\0'};  //存放命令
	int i;

	while(1){  
		printf(" ------------------------菜单----------------------------\n");
		printf("|                    1.创建容器                          |\n");
		printf("|                    2.终止容器                          |\n");
		printf("|                    3.删除容器                          |\n");
		printf("|                    4.查看容器                          |\n");
		printf("|                    5.启动容器				 |\n");
		printf("|                    8.创建固定网段                      |\n");
		printf("|                    9.退出                              |\n");
		printf(" --------------------------------------------------------\n");
		printf("请选择：\n");
		scanf("%s",str1);
		num = atoi(str1);

		switch(num){
			case 1: 
				printf("<请输入要创建的容器个数> \n");
				scanf("%d",&sum);		
			  /*
			  printf("\n");
				printf("<请输入要创建的容器个数> <端口号> <起始IP>\n");
				ret = scanf("%d%d%s",&sum,&port,ip);						
				while(ret !=3){
					printf("输入有误！\n");
					printf("<请重新输入要创建的容器个数> <端口号> <起始IP>\n");
					while((ch = getchar() != '\n' && ch != EOF));  
					ret = scanf("%d%d%s",&sum,&port,ip);
				}


				sprintf(ipbuf1,"%c%c%c",ip[0],ip[1],ip[2]);
				sprintf(ipbuf2,"%c%c%c",ip[4],ip[5],ip[6]);
				sprintf(ipbuf3,"%c%c%c",ip[8],ip[9],ip[10]);
				sprintf(ipbuf4,"%c%c%c",ip[12],ip[13],ip[14]);

				//	printf("%s %s %s %s\n",ipbuf1,ipbuf2,ipbuf3,ipbuf4);

				ipnum1 = atoi(ipbuf1);			
				ipnum2 = atoi(ipbuf2);			
				ipnum3 = atoi(ipbuf3);			
				ipnum4 = atoi(ipbuf4);			

				for(i=0;i<sum;i++){
					if(i == 0){
					  memset(str2,0,sizeof(str2));
					  sprintf(str2,"docker network create --subnet=%d.%d.%d.%d/16 www",ipnum1,ipnum2,ipnum3,ipnum4);
					  system(str2);
					  sleep(1);
					  }				

					printf("创建第 %d 容器\n",i+1);
					memset(str2,0,sizeof(str2));
					sprintf(str2,"docker run -v /test:/soft -d -p %d:2888 --net wwwww --ip %d.%d.%d.%d -ti ubuntu:14.04 /soft/test",port,ipnum1,ipnum2,ipnum3,ipnum4);


					system(str2);

					sleep(8);
					port++; //端口自增1
					ipnum4++;
					if( ipnum4 == 255){
						ipnum3++;
						if(ipnum3 > 255){
							printf("超过IP限制\n");
							exit(1);
						}

						ipnum4 = 1; 
					}
				}

				printf("创建容器完成！！！\n\n");		
				*/

				for(i=0;i<sum;i++){
				printf("创建第 %d 容器\n",i+1);
				system("docker run -v /test:/soft -d  -it ubuntu:14.04 /soft/test");
					sleep(3);

				}
				printf("创建容器完成！！！\n\n");
				break;
			case 2:
				printf("终止容器中......\n\n");				
				printf("----------------------------------------------------------------\n");
				system("docker stop $(docker ps -a | awk '{ print $1}' | tail -n +2)");
				printf("----------------------------------------------------------------\n");
				break;
			case 3:         
				printf("删除所有容器....\n\n");	
				system("docker rm $(docker ps -a | awk '{ print $1}' | tail -n +2)");
				break;
			case 4:
				printf("查看正在运行打容器...\n");						
				system("docker ps -a");
				break;
			case 5:
				printf("正在启动容器......\n");				 
				printf("----------------------------------------------------------------\n");
				system("docker start $(docker ps -a | awk '{ print $1}' | tail -n +2)");
				printf("----------------------------------------------------------------\n");		
				break;
			
			case 8:
					memset(str2,0,sizeof(str2));
					sprintf(str2,"docker network create --subnet=100.100.1.1/16 wwwww");
				    system(str2);
				    sleep(1);
					break;	
			
			case 9:
	


				return 0;
			default:
				printf("没有该选项！！！\n");
				break;

		}

		while((ch = getchar() != '\n' && ch != EOF));			   	

	}


	return 0;
}
