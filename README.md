# Wallace-Tree-Multiplier-VHDL-generator
Generate a Wallace tree multiplier in VHDL using structural style

This is my first repository on github.

The C code "Wallace_tree_multiplier_cadence.c" generates a Wallace tree multiplier, that multiplies two binary numbers of equal bit length as specified by the user.

Included, in this repository, are: 
  1)Wallace_tree_multiplier_cadence.c, 
  2)adder_generator_cadence.c, and
  3)full_adder.vhd.

** The above C codes can be compiled and executed in visual studio, 
   and the .vhd files hence obtained ("Wallace_Tree_Multiplier.vhd" and "adderN.vhd", respectively) must be imported, 
   along with "full_adder.vhd", in cadence virtuoso using import->VHDL.
  
  
** The adderN.vhd must be generated depending on the "adder" used in the generated "Wallace_Tree_Multiplier.vhd" file. 
   N is the integer that follows "adder" in this .vhd file.
  
     For example, if "adder33" appears inside the "Wallace_Tree_Multiplier.vhd" file, then "adder_generator_cadence.c" is used to generate      "adder33.vhd" file. The integer "33" is entered, when prompted to "enter the number of bits of the adder" by the program.
     
** "or2","and2", and "xor2" must be created using cadence virtuoso's schematic editor.


****   Note: The final addition is done using an N-bit ripple carry adder.   ****
