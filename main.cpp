#include "main.h"

int main(int argc, char *argv[])
{
	std::ifstream f, g;
	int c = 0;

	if (argc < 3) {
		std::cout << "Ce programme s'appelle ./gare -r <routes> -v <villes>" << std::endl;
		return 0;
	} else {
		while ((c = getopt(argc, argv, "r:v:")) != -1) {
			switch (c) {
				case 'r' :
					f.open(optarg);
					break;
				case 'v' :
					g.open(optarg);
					break;
				default : // Useless
					std::cout << "Option inconnue : " << c << std::endl;
					return 0;
			}
		}
	}
	
	Railway p(f, g);
	
	f.close();
	g.close();

	return 1;
}
