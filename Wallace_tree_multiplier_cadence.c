#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *fp;

int main() {
	fopen_s(&fp, "Wallace_tree_multiplier.vhd", "w");
	int r;
	int n;
	int c1 = 0;
	int t;
	int c = 0;
	int nt;
	int k2;
	int count_k;
	printf("\n enter the number of bits in the multiplier");
	scanf_s("%d", &n);
	r = n;
	fprintf(fp, "\n                                                                            ");
	fprintf(fp, "\n                                                                            ");
	fprintf(fp, "\n library IEEE;");
	fprintf(fp, "\n use IEEE.std_logic_1164.all;");
	fprintf(fp, "\n use IEEE.std_logic_arith.all;");
	fprintf(fp, "\n use IEEE.std_logic_unsigned.all;");
	fprintf(fp, "\n                                                                            ");
	fprintf(fp, "\n entity walltree_mul is");
	fprintf(fp, "\n \t  port (");
	fprintf(fp, "\n \t \t op1	:	in	std_logic_vector(%d downto 0 );  ", n - 1);
	fprintf(fp, "\n \t \t op2	:	in	std_logic_vector(%d downto 0 );  ", n - 1);
	fprintf(fp, "\n \t \t ext1  :   in  std_logic;");
	fprintf(fp, "\n \t \t vdd : inout std_logic;");
	fprintf(fp, "\n \t \t vss : inout std_logic;");
	fprintf(fp, "\n \t \t result	:      out	std_logic_vector(%d downto 0 )   ", 2 * n + 1);
	fprintf(fp, "\n \t       ); ");
	fprintf(fp, "\n end walltree_mul;");
	fprintf(fp, "\n                                                                              ");
	fprintf(fp, "\n                                                                              ");
	fprintf(fp, "\n                                                                              ");
	fprintf(fp, "\n architecture schematic of walltree_mul is");
	fprintf(fp, "\n 	 component xor2 is");
	fprintf(fp, "\n           port(A,B : in std_logic ;");
	fprintf(fp, "\n                vdd : inout std_logic;");
	fprintf(fp, "\n                vss : inout std_logic;");
	fprintf(fp, "\n                  Y : out std_logic );");
	fprintf(fp, "\n           end component;");
	fprintf(fp, "\n                                       ");
	fprintf(fp, "\n 	 component or2 is");
	fprintf(fp, "\n           port(A,B : in std_logic ;");
	fprintf(fp, "\n                vdd : inout std_logic;");
	fprintf(fp, "\n                vss : inout std_logic;");
	fprintf(fp, "\n                  Y : out std_logic );");
	fprintf(fp, "\n           end component;");
	fprintf(fp, "\n                                      ");
	fprintf(fp, "\n 	 component and2 is");
	fprintf(fp, "\n           port(A,B : in std_logic ;");
	fprintf(fp, "\n                vdd : inout std_logic;");
	fprintf(fp, "\n                vss : inout std_logic;");
	fprintf(fp, "\n                  Y : out std_logic );");
	fprintf(fp, "\n           end component;");
	fprintf(fp, "\n                                      ");
	fprintf(fp, "\n 	 component adder%d is", 2 * n + 1);
	fprintf(fp, "\n           port(A,B : in std_logic_vector(%d downto 0) ;", 2 * n);
	fprintf(fp, "\n                Cin : in std_logic;");
	fprintf(fp, "\n                vdd : inout std_logic;");
	fprintf(fp, "\n                vss : inout std_logic;");
	fprintf(fp, "\n                  Y : out std_logic_vector(%d downto 0) );", 2 * n + 1);
	fprintf(fp, "\n           end component;");
	fprintf(fp, "\n                                       ");
	t = n;


	for (int i = 0; i<n; i = i + 1) {
		fprintf(fp, "\n \t signal pp%d : std_logic_vector(%d downto 0 );", i, n - 1);
	}
	fprintf(fp, "\n                                                                           \n");

	// Declaring the signals
	c = 0;
	t = n;
	while (t >= 3) {
		for (int i = 0; i < t; i = i + 1) {
			fprintf(fp, "\n signal sig%d_%d : std_logic_vector(%d downto 0):=(others=>'0');", c, i, 2 * n);
		}
		c = c + 1;
		t = (2 * (t / 3)) + (t % 3);
	}
	c = 0;
	k2 = 0;
	t = n;
	c = c + 1;
	while (t >= 3) {
		int k_prev = t;
		k2 = (2 * (t / 3)) + (t % 3);
		int i4 = 0;
		int add12 = 0;
		int ad34 = 0;
		while (i4<k2) {
			if ((add12 + 2 + i4) < k_prev) {
				fprintf(fp, "\n signal temp%d%d : std_logic_vector(%d downto 0):=(others=>'0'); ", c, i4, 2 * n);
				fprintf(fp, "\n");
				i4 = i4 + 1;
				fprintf(fp, "\n signal temp%d%d : std_logic_vector(%d downto 0):=(others=>'0');", c, i4, 2 * n);
				fprintf(fp, "\n signal temp_%d%d : std_logic_vector(%d downto 0):=(others=>'0');", c, i4, 2 * n);
				fprintf(fp, "\n signal temp_%d_%d : std_logic_vector(%d downto 0):=(others=>'0');", c, i4, 2 * n);
				fprintf(fp, "\n");
				i4 = i4 + 1;
				add12 = add12 + 1;
			}
			else {
				i4 = i4 + 1;
			}

		}
		c = c + 1;
		t = k2;
	}
	fprintf(fp, "\n signal sig%d_%d : std_logic_vector(%d downto 0):=(others=>'0');", c - 1, 0, 2 * n);
	fprintf(fp, "\n signal sig%d_%d : std_logic_vector(%d downto 0):=(others=>'0');", c - 1, 1, 2 * n);
	fprintf(fp," \n");
	fprintf(fp," \n signal fa1z : std_logic:='0';");
	fprintf(fp," \n");
	c = 0;
	count_k = 0;
	t = n;
	fprintf(fp, "\n begin                                                                       ");
	fprintf(fp, "\n                                                                             ");
	for (int i = 0; i<n; i = i + 1) {
		for (int j = 0; j<n; j = j + 1) {
			count_k = count_k + 1;
			fprintf(fp, "\n temp_and2_pp%d%d%d : and2 port map(op1(%d),op2(%d),vdd,vss,pp%d(%d));", i, j, count_k, i, j, i, j);
		}
	}
	fprintf(fp, "\n                                                                             ");
	t = n;
	nt = n;

	for (int lmnp = 0; lmnp<n; lmnp = lmnp + 1)
	{
		fprintf(fp, "\n sig0_%d(%d downto %d) <= pp%d(%d downto %d);", lmnp,n-1+lmnp,lmnp,lmnp,n-1,0);
		for (int k = 0; k < lmnp; k = k + 1) {
			fprintf(fp, "\n sig0_%d(%d) <= ext1 ;", lmnp, k);
		}
		for (int k = 2*n; k >= t + lmnp; k = k - 1) {
			fprintf(fp, "\n sig0_%d(%d) <= ext1 ;", lmnp, k);
		}
	}
	fprintf(fp,"\n");

	k2 = 0;
	c = c + 1;
	while (t >= 3) {
		int k_prev = t;
		k2 = (2 * (t / 3)) + (t % 3);
		int i4 = 0;
		int add12 = 0;
		int ad34 = 0;
		count_k = 0;
		while (i4<k2) {
			if ((add12 + 2 + i4)<k_prev) {
				for (int i = 2 * n; i >= 0; i = i - 1) {
					count_k = count_k + 1;
					fprintf(fp, "\n s%d%d%d%d : xor2 port map (sig%d_%d(%d),sig%d_%d(%d),vdd,vss,temp%d%d(%d)) ; ", c, i4, i, count_k, (c - 1), (add12 + 0 + i4), i, (c - 1), (add12 + 1 + i4), i, c, i4, i);
					count_k = count_k + 1;
					fprintf(fp, "\n s_%d%d%d%d : xor2 port map (temp%d%d(%d),sig%d_%d(%d),vdd,vss,sig%d_%d(%d)); ", c, i4, i, count_k, c, i4, i, (c - 1), (add12 + 2 + i4), i, c, i4, i);
					fprintf(fp, "\n");
				}
				i4 = i4 + 1;
				for (int i = 2 * n; i >= 1; i = i - 1) {
					count_k = count_k + 1;
					fprintf(fp, "\n S%d%d%d%d : and2 port map(sig%d_%d(%d),sig%d_%d(%d),vdd,vss,temp%d%d(%d));", c, i4, i, count_k, c - 1, add12 - 1 + i4, i - 1, c - 1, add12 + 0 + i4, i - 1, c, i4, i - 1);
					count_k = count_k + 1;
					fprintf(fp, "\n S_%d%d%d%d : xor2 port map(sig%d_%d(%d),sig%d_%d(%d),vdd,vss,temp_%d%d(%d));", c, i4, i, count_k, c - 1, add12 - 1 + i4, i - 1, c - 1, add12 + 0 + i4, i - 1, c, i4, i - 1);
					count_k = count_k + 1;
					fprintf(fp, "\n S_%d_%d%d%d : and2 port map(sig%d_%d(%d),temp_%d%d(%d),vdd,vss,temp_%d_%d(%d));", c, i4, i, count_k, c - 1, add12 + 1 + i4, i - 1, c, i4, i - 1, c, i4, i - 1);
					count_k = count_k + 1;
					fprintf(fp, "\n S_%d_%d_%d%d : or2 port map(temp%d%d(%d),temp_%d_%d(%d),vdd,vss,sig%d_%d(%d));", c, i4, i, count_k, c, i4, i - 1, c, i4, i - 1, c, i4, i);
					fprintf(fp, "\n");
				}
				i4 = i4 + 1;
				add12 = add12 + 1;
			}
			if ((add12 + 2 + i4) >= k_prev && i4 != k2) {
				fprintf(fp, "\n sig%d_%d <= sig%d_%d ;", c, i4, c - 1, add12 + i4);
				i4 = i4 + 1;
			}
		}
		c = c + 1;
		t = k2;
	}

	fprintf(fp, "\n RSLT : adder%d port map (sig%d_%d,sig%d_%d,ext1,vdd,vss,result);", 2 * n + 1, c - 1, 0, c - 1, 1);
	fprintf(fp, "\n");
	fprintf(fp, "\n end;");
	fclose(fp);
}