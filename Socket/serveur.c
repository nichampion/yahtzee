#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<netdb.h>
#include <signal.h>
#include <unistd.h>
char buffer[512];

void fin(int sig){
	printf("fin du serveur");
}

int hostname_to_ip(char * hostname , char* ip)
{
    struct hostent *he;
    struct in_addr **addr_list;
    int i;
         
    if ( (he = gethostbyname( hostname ) ) == NULL) 
    {
        // get the host info
        herror("gethostbyname");
        return 1;
    }
 
    addr_list = (struct in_addr **) he->h_addr_list;
     
    for(i = 0; addr_list[i] != NULL; i++) 
    {
        //Return the first one;
        strcpy(ip , inet_ntoa(*addr_list[i]) );
        return 0;
    }
     
    return 1;
}


void view_ip()
{
  char s[256];
  struct hostent *host;
  struct in_addr **adr;
  if (!gethostname(s, 256))
    if ((host = gethostbyname(s)) != NULL)
      for (adr = (struct in_addr **)host->h_addr_list; *adr; adr++)
          printf("IP : %s\n", inet_ntoa(**adr));
}

int main ( void )
{
	int ma_socket;
	int client_socket;
	struct sockaddr_in mon_address, client_address;
	unsigned int mon_address_longueur, lg;
	bzero(&mon_address,sizeof(mon_address));
	mon_address.sin_port = htons(30000);
	mon_address.sin_family = AF_INET;
	mon_address.sin_addr.s_addr = htonl(INADDR_ANY);

	char *hostname = "localhost";
    char ip[100];
     
    hostname_to_ip(hostname , ip);
	fprintf(stderr, "%s resolved to %s" , hostname , ip);
	view_ip();

	/* creation de socket */
	if ((ma_socket = socket(AF_INET,SOCK_STREAM,0))== -1) {
		printf("Impossible de créer la socket\n");
		exit(0);
	}

	/* bind serveur - socket */
	bind(ma_socket,(struct sockaddr *)&mon_address,sizeof(mon_address));
	/* ecoute sur la socket */
	listen(ma_socket,5);
	/* accept la connexion */
	mon_address_longueur = sizeof(client_address);
	
    /* on attend que le client se connecte */
	client_socket = accept(ma_socket,
                         (struct sockaddr *)&client_address,
                         &mon_address_longueur);
    
	int quitter=0;
    while(!quitter)
	{
		memset(buffer, 0, sizeof(buffer));
		lg = recv(client_socket, buffer, 512,0);
		
		if(strncmp("MSG", buffer, 3)==0){
			printf("[serveur] message reçu : '%s'\n",buffer+4);
			printf("[serveur] envoi de la réponse ");
			sprintf(buffer,"REPONSE DU SERVEUR");
			send(client_socket, buffer, 512, 0);
		} else if(strncmp("QUITTER", buffer, 7) == 0) {
			printf("[serveur] déconnexion demandée : '%s'\n",buffer);
			shutdown(client_socket,2);
			close(client_socket);
			quitter=1;
		} else if(strncmp("BONJOUR", buffer, 7) == 0){
			printf("[serveur] BONJOUR d'un client\n");
			send(client_socket, "BONJOUR", 7, 0);
		} else {
			printf("[serveur] message inconnu : '%s'\n", buffer);
		}
	}
	shutdown(ma_socket,2);
	close(ma_socket);
	return 0;
}



