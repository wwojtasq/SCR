#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

int main()
{
  int id=fork();
  int fd;
  int gd; //nowy deskryptor obrazu
  int rozmiar;
  char nazwa[64];
  char* zmapowane="mapowanie";
  struct stat st;

  if(id==0)
    {
      while(1)
	{
	  execlp("display","display","-update","1","mapowanie",NULL);
	}
      exit(1);
    }

  if(id>0)
    {
      while(1)
	{
	  printf("Podaj nazwe obrazka:\n");
	  scanf("%s",nazwa);

	  fd=open(nazwa,O_RDONLY);
	  stat(nazwa,&st); //zbiera wlasciwosci pliku
	  rozmiar = st.st_size;

	  gd = open(zmapowane,O_RDWR); //otwieranie pliku

	  ftruncate(gd,rozmiar); //czyszczenie pamieci pliku

	  char* mapa = mmap(NULL,rozmiar,PROT_READ | PROT_WRITE, MAP_SHARED,gd,0); // adres,wielkosc,uprawnienia,mapowanie w innych procesach, deskrtyptor,offser

	  read(fd,mapa,rozmiar); // czytanie

	  msync(mapa,rozmiar,MS_SYNC); //synchronizacja
	  close(fd); //zamkniecia
	  close(gd);

	}

    }
  return 0;
}

