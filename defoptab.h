#ifndef DEFOPTAB_H
#define DEFOPTAB_H
#include<iostream>
using namespace std;
class optab{
	public:
		string opcode;
		string operation;
	
		
};
optab opobject[42];	
void opcd(){

opobject[0].operation="ADD";opobject[0].opcode="18";
opobject[1].operation="ADDF";opobject[1].opcode="58";
opobject[2].operation="AND";opobject[2].opcode="40";
opobject[3].operation="COMP";opobject[3].opcode="28";
opobject[4].operation="COMPF";opobject[4].opcode="88";
opobject[5].operation="DIV";opobject[5].opcode="24";
opobject[6].operation="DIVF";opobject[6].opcode="64";
opobject[7].operation="J";opobject[7].opcode="3C";
opobject[8].operation="JEQ";opobject[8].opcode="30";
opobject[9].operation="JGT";opobject[9].opcode="34";
opobject[10].operation="JLT";opobject[10].opcode="38";
opobject[11].operation="JSUB";opobject[11].opcode="48";
opobject[12].operation="LDA";opobject[12].opcode="00";
opobject[13].operation="LDB";opobject[13].opcode="68";
opobject[14].operation="LDCH";opobject[14].opcode="50";
opobject[15].operation="LDF";opobject[15].opcode="70";
opobject[16].operation="LDL";opobject[16].opcode="08";
opobject[17].operation="LDS";opobject[17].opcode="6C";
opobject[18].operation="LDT";opobject[18].opcode="74";
opobject[19].operation="LDX";opobject[19].opcode="04";
opobject[20].operation="LPS";opobject[20].opcode="D0";
opobject[21].operation="MUL";opobject[21].opcode="20";
opobject[41].operation="MULF";opobject[41].opcode="60";
opobject[22].operation="OR";opobject[22].opcode="44";
opobject[23].operation="RD";opobject[23].opcode="D8";
opobject[24].operation="RSUB";opobject[24].opcode="4C";
opobject[25].operation="SSK";opobject[25].opcode="EC";
opobject[26].operation="STA";opobject[26].opcode="0C";
opobject[27].operation="STB";opobject[27].opcode="78";
opobject[28].operation="STCH";opobject[28].opcode="54";
opobject[29].operation="STF";opobject[29].opcode="80";
opobject[30].operation="STI";opobject[30].opcode="D4";
opobject[31].operation="STL";opobject[31].opcode="14";
opobject[32].operation="STS";opobject[32].opcode="7C";
opobject[33].operation="STSW";opobject[33].opcode="E8";
opobject[34].operation="STT";opobject[34].opcode="84";
opobject[35].operation="STX";opobject[35].opcode="10";
opobject[36].operation="SUB";opobject[36].opcode="1C";
opobject[37].operation="SUBF";opobject[37].opcode="SUBF";
opobject[38].operation="TD";opobject[38].opcode="E0";
opobject[39].operation="TIX";opobject[39].opcode="2C";
opobject[40].operation="WD";opobject[40].opcode="DC";
}

#endif
