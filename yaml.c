#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
struct adaptador{
	const char *nombre;
	const char *dhcp;
	const char *address;
	const char *gateway;
	const char *dns;
};
int no_interactivo(struct adaptador *red){
const char ruta[] ="00-installer-config.yaml";
FILE *f = fopen(ruta,"w");
        if(f==NULL){return 1;}
        fprintf(f,"network:\n  version: 2\n  renderer: NetworkManager\n  ethernets:\n");
        fprintf(f,"    %s:\n",red->nombre);
        fprintf(f,"      dhcp4: %s\n",red->dhcp);
        fprintf(f,"      addresses:\n        - %s\n",red->address);
	fprintf(f,"      routes:\n");
	fprintf(f,"        - to: default\n");
	fprintf(f,"          via: %s\n",red->gateway);
	fprintf(f,"      nameservers:\n");
	fprintf(f,"        addresses:\n");
	fprintf(f,"          - %s\n",red->dns);
	fprintf(f,"          - 8.8.8.8\n");
	fclose(f);
	chmod(ruta,0600);
        return 0;
}
int main (int args,char *argv[]){
	struct adaptador red;
	red.nombre = argv[1];
	red.dhcp = argv[2];
	red.address = argv[3];
	red.gateway = argv[4];
	red.dns = argv[5];
	no_interactivo(&red);
}
/*void interactive(struct adaptador *red){
}*/
