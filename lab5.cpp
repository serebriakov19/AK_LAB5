#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>


int main (int argc, char *argv[]){

	const char* short_options = "hs::f:";

	const struct option long_options[] = {
		{"help",no_argument,NULL,'h'},
		{"size",optional_argument,NULL,'s'},
		{"file",required_argument,NULL,'f'},
		{NULL,0,NULL,0}
	};

	bool HELP=true;
	bool SIZE=true;
	bool FILE=true;
	int rez;
	int option_index=-1;

	while ((rez=getopt_long(argc,argv,short_options,
		long_options,&option_index))!=-1){

		switch(rez){
			case 'h': {
				if (option_index<0 && HELP)
					printf("short help option\n");
				else 
					if(HELP)
						printf("option_index = %d (\"%s\",%d,%c)\n",
							option_index,
							long_options[option_index].name,
							long_options[option_index].has_arg,
							long_options[option_index].val
						);
				HELP=false;
				break;
			};
			case 's': {
				if (optarg!=NULL && SIZE)
					printf("found size with value %s\n",optarg);
				else 
					if(SIZE)
						printf("found size without value\n");
				SIZE=false;
				break;
			};
	
			case 'f': {
				if (FILE)
				{
					printf("file = %s\n",optarg);
				}
				FILE=false;
				break;
			};
			case '?': default: {
				printf("found unknown option\n");
				break;
			};
		};
	};
	return 0;
};