 #include<stdlib.h>
 #include<stdio.h>
 #include<string.h>
 #include<unistd.h>
 #include<sys/types.h>
 #include<sys/ipc.h>
 #include<sys/msg.h>
 struct my_msg{
         long int msg_type;
         char some_text[BUFSIZ];
 };
 int main()
 {
         int msgid;
         struct my_msg data;
         long int msg_to_rec=0;
         msgid=msgget((key_t)14534,0666|IPC_CREAT);
         while(1)
         {
                 msgrcv(msgid,(void *)&data,BUFSIZ,msg_to_rec,0);                 
                 printf("Data received: %s\n",data.some_text);
                 if(strncmp(data.some_text,"end",3)==0)
                 {
                         break;
                 }
         }
          msgctl(msgid,IPC_RMID,0);
 }
