#include <stdio.h>

struct adaptador{
	const char *nombre;
	const char *dhcp;
	const char *address;
	const char *gateway;
	const char *dns;
};
int no_interactivo(struct adaptador *red){
	FILE *f = fopen("00-installer-config.yaml","w");
	if(f==NULL){return 1;}
	fprintf(f,"network:\n  version: 2\n  ethernets:\n");
	fprintf(f,"   %s:\n",red->nombre);
	fprintf(f,"    dhcp4: %s\n",red->dhcp);
	fprintf(f,"    addresses:\n    - %s\n",red->address);
	fprintf(f,"    gateway4: %s\n",red->gateway);
	fprintf(f,"    nameservers:\n     addresses: [%s]",red->dns);
	fclose(f);
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
