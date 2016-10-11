#include <stdio.h>
#include "graphics.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stddef.h>

int compteur[3]={0, 0, 0}, nbre;

struct disquetour{
		int posX;
                int posY;
                int rayonH;
                int rayonV;
                int colR;
                int colG;
                int colB;
        } *tour1, *tour2, *tour3;

void deplacehaut(struct disquetour d1){
		int h=d1.posY;
		while(h<550){
			h=h+5;
			gr_set_color(RGB(d1.colR,d1.colG,d1.colB));
			gr_draw_ellispe(d1.posX, h, d1.rayonH, d1.rayonV);
			usleep(10000);
			gr_set_color(white);
			gr_draw_ellispe(d1.posX, h, d1.rayonH, d1.rayonV);
			if(h<=500){
				gr_moveto(d1.posX, (h-d1.rayonV));
				gr_set_color(yellow);
				gr_lineto(d1.posX, (h+d1.rayonV));
				}
			}
}

void deplacevertical(struct disquetour d2, int td2, int ta2){
		int l=d2.posX;
		if(td2==1 && ta2==2){
			while(l<600){
				l=l+5;
				gr_set_color(RGB(d2.colR,d2.colG,d2.colB));
				gr_draw_ellispe(l, 550, d2.rayonH, d2.rayonV);
				usleep(10000);
				gr_set_color(white);
				gr_draw_ellispe(l, 550, d2.rayonH, d2.rayonV);
			}
		}
		if(td2==1 && ta2==3){
			while(l<1000){
				l=l+5;
				gr_set_color(RGB(d2.colR,d2.colG,d2.colB));
				gr_draw_ellispe(l, 550, d2.rayonH, d2.rayonV);
				usleep(10000);
				gr_set_color(white);
				gr_draw_ellispe(l, 550, d2.rayonH, d2.rayonV);
			}
		}
		if(td2==2 && ta2==1){
			while(l>200){
				l=l-5;
				gr_set_color(RGB(d2.colR,d2.colG,d2.colB));
				gr_draw_ellispe(l, 550, d2.rayonH, d2.rayonV);
				usleep(10000);
				gr_set_color(white);
				gr_draw_ellispe(l, 550, d2.rayonH, d2.rayonV);
			}
		}
		if(td2==2 && ta2==3){
			while(l<1000){
				l=l+5;
				gr_set_color(RGB(d2.colR,d2.colG,d2.colB));
				gr_draw_ellispe(l, 550, d2.rayonH, d2.rayonV);
				usleep(10000);
				gr_set_color(white);
				gr_draw_ellispe(l, 550, d2.rayonH, d2.rayonV);
			}
		}
		if(td2==3 && ta2==2){
			while(l>600){
				l=l-5;
				gr_set_color(RGB(d2.colR,d2.colG,d2.colB));
				gr_draw_ellispe(l, 550, d2.rayonH, d2.rayonV);
				usleep(10000);
				gr_set_color(white);
				gr_draw_ellispe(l, 550, d2.rayonH, d2.rayonV);
			}
		}
		if(td2==3 && ta2==1){
			while(l>200){
				l=l-5;
				gr_set_color(RGB(d2.colR,d2.colG,d2.colB));
				gr_draw_ellispe(l, 550, d2.rayonH, d2.rayonV);
				usleep(10000);
				gr_set_color(white);
				gr_draw_ellispe(l, 550, d2.rayonH, d2.rayonV);
			}
		}
}

void deplacebas(struct disquetour d3, int ta3){
	int h=550;
	if(ta3==1){
		while(h>100+((compteur[0]+1)*(400/nbre))){
			h=h-5;
			gr_set_color(RGB(d3.colR,d3.colG,d3.colB));
			gr_draw_ellispe(200, h, d3.rayonH, d3.rayonV);
			usleep(10000);
			gr_set_color(white);
			gr_draw_ellispe(200, h, d3.rayonH, d3.rayonV);
			if(h<=500){
				gr_moveto(200, (h-d3.rayonV));
				gr_set_color(yellow);
				gr_lineto(200, (h+d3.rayonV));
			}
		}
	}
	if(ta3==2){
		while(h>100+((compteur[1]+1)*(400/nbre))){
			h=h-5;
			gr_set_color(RGB(d3.colR,d3.colG,d3.colB));
			gr_draw_ellispe(600, h, d3.rayonH, d3.rayonV);
			usleep(10000);
			gr_set_color(white);
			gr_draw_ellispe(600, h, d3.rayonH, d3.rayonV);
			if(h<=500){
				gr_moveto(600, (h-d3.rayonV));
				gr_set_color(yellow);
				gr_lineto(600, (h+d3.rayonV));
			}
		}
	}
	if(ta3==3){
		while(h>100+((compteur[2]+1)*(400/nbre))){
			h=h-5;
			gr_set_color(RGB(d3.colR,d3.colG,d3.colB));
			gr_draw_ellispe(1000, h, d3.rayonH, d3.rayonV);
			usleep(10000);
			gr_set_color(white);
			gr_draw_ellispe(1000, h, d3.rayonH, d3.rayonV);
			if(h<=500){
				gr_moveto(1000, (h-d3.rayonV));
				gr_set_color(yellow);
				gr_lineto(1000, (h+d3.rayonV));
			}
		}
	}
}

void deplace(struct disquetour d, int td, int ta){
	gr_set_line_width(4);
	gr_set_color(white);
	gr_draw_ellispe(d.posX, d.posY, d.rayonH, d.rayonV);
	gr_moveto(d.posX, (d.posY-d.rayonV));
	gr_set_color(yellow);
	gr_lineto(d.posX, (d.posY+d.rayonV));
	deplacehaut(d);
	deplacevertical(d, td, ta);
	deplacebas(d, ta);
	compteur[td-1]--;
	gr_set_color(RGB(d.colR,d.colG,d.colB));
	if(ta==1){
		gr_draw_ellispe(200, (100+((compteur[0]+1)*(400/nbre))), d.rayonH, d.rayonV);
		compteur[0]++;
		tour1[(compteur[0])].posX=200;
		tour1[(compteur[0])].posY=(100+((compteur[0])*(400/nbre)));
		tour1[(compteur[0])].rayonH=d.rayonH;
		tour1[(compteur[0])].rayonV=d.rayonV;
		tour1[(compteur[0])].colR=d.colR;
                tour1[(compteur[0])].colB=d.colB;
                tour1[(compteur[0])].colG=d.colG;
	}
	else if(ta==2){
                gr_draw_ellispe(600, (100+((compteur[1]+1)*(400/nbre))), d.rayonH, d.rayonV);
                compteur[1]++;
				tour2[(compteur[1])].posX=600;
                tour2[(compteur[1])].posY=(100+((compteur[1])*(400/nbre)));
                tour2[(compteur[1])].rayonH=d.rayonH;
                tour2[(compteur[1])].rayonV=d.rayonV;
				tour2[(compteur[1])].colR=d.colR;
                tour2[(compteur[1])].colB=d.colB;
                tour2[(compteur[1])].colG=d.colG;
        }
	else{
                gr_draw_ellispe(1000, (100+((compteur[2]+1)*(400/nbre))), d.rayonH, d.rayonV);
                compteur[2]++;
				tour3[(compteur[2])].posX=1000;
                tour3[(compteur[2])].posY=(100+((compteur[2])*(400/nbre)));
                tour3[(compteur[2])].rayonH=d.rayonH;
                tour3[(compteur[2])].rayonV=d.rayonV;
				tour3[(compteur[2])].colR=d.colR;
                tour3[(compteur[2])].colB=d.colB;
                tour3[(compteur[2])].colG=d.colG;
        }
	usleep(100000);
}

hanoi(int nh, int tdh, int tah, int tih){
	if(nh==1){
		if(tdh==1) deplace(tour1[(compteur[0])], tdh, tah);
		else if(tdh==2) deplace(tour2[(compteur[1])], tdh, tah);
		else if(tdh==3) deplace(tour3[(compteur[2])], tdh, tah);
	}
	else{
		hanoi((nh-1), tdh, tih, tah);
		if(tdh==1) deplace(tour1[(compteur[0])], tdh, tah);
        else if(tdh==2) deplace(tour2[(compteur[1])], tdh, tah);
        else if(tdh==3) deplace(tour3[(compteur[2])], tdh, tah);
		hanoi((nh-1), tih, tah, tdh);
	}
}

main(){
	char str[5],car='0';
	int r,g,b,i=0;
	gr_open_graph(" 1200x600");
	gr_moveto(400, 300);
	gr_draw_string("Entrez le nombre de disques");
	while(car=='0' || car=='1' || car=='2' || car=='3' || car=='4' || car=='5' || car=='6' || car=='7' || car=='8' || car=='9'){
		car=gr_read_key();
		gr_moveto((600+(6*i)),300);
		gr_draw_char(car);
		str[i]=car;
		i++;
		str[i]='\0';
	}
	gr_clear_graph();
	nbre=atoi(str);
	tour1 = (struct disquetour *) malloc((sizeof(struct disquetour))*nbre);
	tour2 = (struct disquetour *) malloc((sizeof(struct disquetour))*nbre);
	tour3 = (struct disquetour *) malloc((sizeof(struct disquetour))*nbre);
	gr_set_color(black);
	gr_fill_ellipse(200, 100, 150, 40);
	gr_fill_ellipse(600, 100, 150, 40);
	gr_fill_ellipse(1000, 100, 150, 40);
	gr_set_line_width(4);
	gr_set_color(yellow);
	gr_moveto(200, 100);
	gr_lineto(200, 500);
	gr_moveto(600, 100);
	gr_lineto(600, 500);
	gr_moveto(1000, 100);
	gr_lineto(1000, 500);
	for(i=1;i<=nbre;i++){
		r=rand()%256;
		b=rand()%256;
		g=rand()%256;
		gr_set_color(RGB(r,g,b));
		gr_draw_ellispe(200, (100+(i*(400/nbre))), ((150/nbre)*(nbre-i+1)), ((40/nbre)*(nbre-i+1)));
		compteur[0]++;
		tour1[(compteur[0])].posX=200;
		tour1[(compteur[0])].posY=(100+(i*(400/nbre)));
		tour1[(compteur[0])].rayonH=((150/nbre)*(nbre-i+1));
		tour1[(compteur[0])].rayonV=((40/nbre)*(nbre-i+1));
		tour1[(compteur[0])].colR=r;
		tour1[(compteur[0])].colB=b;
		tour1[(compteur[0])].colG=g;
		sleep(1);
	}
	hanoi(nbre, 1, 3, 2);
	gr_wait_event(KEY_PRESSED);
	gr_close_graph();
}
