#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *fp;

int main(){
fopen_s(&fp,"adder.vhd","w");
int n;
printf("\n enter the number of bits of the adder");
scanf_s("%d",&n);
fprintf(fp,"\n library IEEE;");
fprintf(fp,"\n use IEEE.STD_LOGIC_1164.ALL;");
fprintf(fp,"\n ");
fprintf(fp,"\n entity adder%d is",n);
fprintf(fp,"\n Port ( A : in STD_LOGIC_VECTOR (%d downto 0);",n-1);
fprintf(fp,"\n \t B : in STD_LOGIC_VECTOR (%d downto 0);",n-1);
fprintf(fp, "\n \t \t vdd : inout STD_LOGIC;");
fprintf(fp, "\n \t \t vss : inout STD_LOGIC;");
fprintf(fp,"\n \t Y : out STD_LOGIC_VECTOR (%d downto 0)",n);
fprintf(fp,"\n );");
fprintf(fp,"\n end adder%d ;",n);
fprintf(fp,"\n            ");
fprintf(fp,"\n architecture schematic of adder%d is",n);
fprintf(fp,"\n                                         ");
fprintf(fp,"\n component full_adder");
fprintf(fp,"\n Port ( A : in STD_LOGIC;");
fprintf(fp,"\n \t B : in STD_LOGIC;");
fprintf(fp,"\n \t Cin : in STD_LOGIC;");
fprintf(fp, "\n \t vdd : inout STD_LOGIC;");
fprintf(fp, "\n \t vss : inout STD_LOGIC;");
fprintf(fp,"\n \t S : out STD_LOGIC;");
fprintf(fp,"\n \t Cout : out STD_LOGIC");
fprintf(fp,"\n );");
fprintf(fp,"\n end component;");
fprintf(fp,"\n                          ");
fprintf(fp,"\n signal ");
for(int i=1;i<n;i=i+1){
  if(i!=n-1){
   fprintf(fp,"c%d,",i);}
  if(i==n-1){
   fprintf(fp,"c%d: STD_LOGIC;",i);}
}
fprintf(fp,"\n signal fa1z : STD_LOGIC:='0';");
fprintf(fp,"\n ");
fprintf(fp,"\n begin");
for(int i=0;i<=n;i=i+1){
if(i==0){fprintf(fp,"\n FA1: full_adder port map( A(0), B(0), fa1z , vdd,vss, C(0), c1);");}
if(i>0 && i<n-1){fprintf(fp,"\n FA%d: full_adder port map( A(%d), B(%d), c%d, vdd,vss,C(%d), c%d);",i+1,i,i,i,i,i+1);}
if(i==n-1){fprintf(fp,"\n FA%d: full_adder port map( A(%d), B(%d), c%d, vdd,vss,C(%d),C(%d));",n,n-1,n-1,n-1,n-1,n); }
}
fprintf(fp,"\n end schematic;");
fclose(fp);
}