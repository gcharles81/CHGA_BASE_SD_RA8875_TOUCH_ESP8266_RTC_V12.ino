/*********************************************************************/
//
//	brief: This file provides an easy way to obtain image data information.
//
//
//	BINARY_INFO[PICTURE_NAME].number      => To obtain sequence number information of the "PICTURE_NAME"(.bmp or .jpg) which is generated in the excel file
//	BINARY_INFO[PICTURE_NAME].img_width       => To obtain image width information of the "PICTURE_NAME" (.bmp or .jpg)
//	BINARY_INFO[PICTURE_NAME].img_height      => To obtain image height information of the "PICTURE_NAME" (.bmp or .jpg)
//	BINARY_INFO[PICTURE_NAME].img_size        => To obtain an image size which is converted and stored in the binary file, please notice, the binary file is combined and converted from the several files (.bmp or .jpg)
//	BINARY_INFO[PICTURE_NAME].start_addr  => To obtain start address of binary file which is converted from the file "PICTURE_NAME" (.bmp or .jpg)
//
//	For example, the struct and enum type as:
//
//	const INFO (code) BINARY_INFO[3]=
//	{
//  	/*  No. , Width , Height , Size (bytes) , Start Address  */
//  	{1,1280,800,2048000,0},          /*     pic_01_1280x800 , element 0     */
//  	{2,320,240,153600,2048000},      /*     RAiO , element 1     */
//  	{3,128,128,32768,2201600},       /*     S1_16 , element 2     */
//	}
//
//
//  typedef enum
//  {
//    pic_01_1280x800=0,  /*     0     */
//    RAiO,               /*     1     */
//    S1_16,              /*     2     */
//  }PICTURE_NAME;
//
//	(1).  To obtain size informations of the file "pic_01_1280x800" (.bmp or jpg),
//        the C code is:
//
//									long param1 = 0;
//
//									param1 = BINARY_INFO[pic_01_1280x800].img_size;
//									/*  or  */
//									param1 = BINARY_INFO[0].img_size;
//
//									/* the param1 is 2048000 (bytes) */
//
//
//	(2).  To obtain start address informations of the file "S1_16" (.bmp or jpg),
//        the C code is:
//
//									long param2 = 0;
//
//									param2 = BINARY_INFO[S1_16].start_addr;
//									/*  or  */
//									param2 = BINARY_INFO[2].start_addr;
//
//									/* the param2 is 2201600 (bytes) */
//
/*********************************************************************/
typedef struct _info
{
	unsigned short number;
	unsigned short img_width;
	unsigned short img_height;
	unsigned long img_size;
	unsigned long start_addr;
}INFO;

/* The 'code' is KEIL C 8051 instruction, please refer to http://www.keil.com/support/man/docs/c51/c51_le_code.htm */
/* If you do not use the 8051 microcontroller system, please remove the 'code' instruction. */

const INFO B_INFO[177] =
{
	/*  No. , Width , Height , Size , Start Address  */
	{ 1,57,57,6498,0 },          /*     A_PIC1 , element 0     */
	{ 2,57,57,6498,6498 },          /*     A_PIC2 , element 1     */
	{ 3,57,57,6498,12996 },          /*     A_PIC3 , element 2     */
	{ 4,57,57,6498,19494 },          /*     A_PIC4 , element 3     */
	{ 5,57,57,6498,25992 },          /*     A_PIC5 , element 4     */
	{ 6,57,57,6498,32490 },          /*     A_PIC6 , element 5     */
	{ 7,57,57,6498,38988 },          /*     A_PIC7 , element 6     */
	{ 8,57,57,6498,45486 },          /*     A_PIC8 , element 7     */
	{ 9,57,57,6498,51984 },          /*     A_PIC9 , element 8     */
	{ 10,57,57,6498,58482 },          /*     A_PIC10 , element 9     */
	{ 11,57,57,6498,64980 },          /*     A_PIC11 , element 10     */
	{ 12,57,57,6498,71478 },          /*     A_PIC12 , element 11     */
	{ 13,57,57,6498,77976 },          /*     A_PIC13 , element 12     */
	{ 14,57,57,6498,84474 },          /*     A_PIC14 , element 13     */
	{ 15,57,57,6498,90972 },          /*     A_PIC15 , element 14     */
	{ 16,57,57,6498,97470 },          /*     A_PIC16 , element 15     */
	{ 17,57,57,6498,103968 },          /*     A_PIC17 , element 16     */
	{ 18,57,57,6498,110466 },          /*     A_PIC18 , element 17     */
	{ 19,57,57,6498,116964 },          /*     A_PIC19 , element 18     */
	{ 20,57,57,6498,123462 },          /*     A_PIC20 , element 19     */
	{ 21,57,57,6498,129960 },          /*     A_PIC21 , element 20     */
	{ 22,57,57,6498,136458 },          /*     A_PIC22 , element 21     */
	{ 23,57,57,6498,142956 },          /*     A_PIC23 , element 22     */
	{ 24,57,57,6498,149454 },          /*     A_PIC24 , element 23     */
	{ 25,57,57,6498,155952 },          /*     A_PIC25 , element 24     */
	{ 26,57,57,6498,162450 },          /*     A_PIC26 , element 25     */
	{ 27,57,57,6498,168948 },          /*     A_PIC27 , element 26     */
	{ 28,57,57,6498,175446 },          /*     A_PIC28 , element 27     */
	{ 29,57,57,6498,181944 },          /*     A_PIC29 , element 28     */
	{ 30,57,57,6498,188442 },          /*     A_PIC30 , element 29     */
	{ 31,57,57,6498,194940 },          /*     A_PIC31 , element 30     */
	{ 32,57,57,6498,201438 },          /*     A_PIC32 , element 31     */
	{ 33,57,57,6498,207936 },          /*     A_PIC33 , element 32     */
	{ 34,57,57,6498,214434 },          /*     A_PIC34 , element 33     */
	{ 35,57,57,6498,220932 },          /*     A_PIC35 , element 34     */
	{ 36,57,57,6498,227430 },          /*     A_PIC36 , element 35     */
	{ 37,57,57,6498,233928 },          /*     A_PIC37 , element 36     */
	{ 38,57,57,6498,240426 },          /*     A_PIC38 , element 37     */
	{ 39,57,57,6498,246924 },          /*     A_PIC39 , element 38     */
	{ 40,57,57,6498,253422 },          /*     A_PIC40 , element 39     */
	{ 41,57,57,6498,259920 },          /*     A_PIC41 , element 40     */
	{ 42,57,57,6498,266418 },          /*     A_PIC42 , element 41     */
	{ 43,57,57,6498,272916 },          /*     A_PIC43 , element 42     */
	{ 44,57,57,6498,279414 },          /*     A_PIC44 , element 43     */
	{ 45,57,57,6498,285912 },          /*     A_PIC45 , element 44     */
	{ 46,57,57,6498,292410 },          /*     A_PIC46 , element 45     */
	{ 47,57,57,6498,298908 },          /*     A_PIC47 , element 46     */
	{ 48,57,57,6498,305406 },          /*     A_PIC48 , element 47     */
	{ 49,57,57,6498,311904 },          /*     A_PIC49 , element 48     */
	{ 50,57,57,6498,318402 },          /*     A_PIC50 , element 49     */
	{ 51,57,57,6498,324900 },          /*     A_PIC51 , element 50     */
	{ 52,57,57,6498,331398 },          /*     A_PIC52 , element 51     */
	{ 53,57,57,6498,337896 },          /*     A_PIC53 , element 52     */
	{ 54,57,57,6498,344394 },          /*     A_PIC54 , element 53     */
	{ 55,57,57,6498,350892 },          /*     A_PIC55 , element 54     */
	{ 56,57,57,6498,357390 },          /*     A_PIC56 , element 55     */
	{ 57,57,57,6498,363888 },          /*     A_PIC57 , element 56     */
	{ 58,57,57,6498,370386 },          /*     A_PIC58 , element 57     */
	{ 59,57,57,6498,376884 },          /*     A_PIC59 , element 58     */
	{ 60,57,57,6498,383382 },          /*     A_PIC60 , element 59     */
	{ 61,57,57,6498,389880 },          /*     A_PIC61 , element 60     */
	{ 62,57,57,6498,396378 },          /*     A_PIC62 , element 61     */
	{ 63,57,57,6498,402876 },          /*     A_PIC63 , element 62     */
	{ 64,57,57,6498,409374 },          /*     A_PIC64 , element 63     */
	{ 65,57,57,6498,415872 },          /*     A_PIC65 , element 64     */
	{ 66,57,57,6498,422370 },          /*     A_PIC66 , element 65     */
	{ 67,57,57,6498,428868 },          /*     A_PIC67 , element 66     */
	{ 68,57,57,6498,435366 },          /*     A_PIC68 , element 67     */
	{ 69,57,57,6498,441864 },          /*     A_PIC69 , element 68     */
	{ 70,57,57,6498,448362 },          /*     A_PIC70 , element 69     */
	{ 71,57,57,6498,454860 },          /*     A_PIC71 , element 70     */
	{ 72,57,57,6498,461358 },          /*     A_PIC72 , element 71     */
	{ 73,57,57,6498,467856 },          /*     A_PIC73 , element 72     */
	{ 74,57,57,6498,474354 },          /*     A_PIC74 , element 73     */
	{ 75,57,57,6498,480852 },          /*     A_PIC75 , element 74     */
	{ 76,57,57,6498,487350 },          /*     A_PIC76 , element 75     */
	{ 77,57,57,6498,493848 },          /*     A_PIC77 , element 76     */
	{ 78,57,57,6498,500346 },          /*     A_PIC78 , element 77     */
	{ 79,57,57,6498,506844 },          /*     A_PIC79 , element 78     */
	{ 80,57,57,6498,513342 },          /*     A_PIC80 , element 79     */
	{ 81,57,57,6498,519840 },          /*     A_PIC81 , element 80     */
	{ 82,57,57,6498,526338 },          /*     A_PIC82 , element 81     */
	{ 83,57,57,6498,532836 },          /*     A_PIC83 , element 82     */
	{ 84,57,57,6498,539334 },          /*     A_PIC84 , element 83     */
	{ 85,57,57,6498,545832 },          /*     A_PIC85 , element 84     */
	{ 86,57,57,6498,552330 },          /*     A_PIC86 , element 85     */
	{ 87,57,57,6498,558828 },          /*     A_PIC87 , element 86     */
	{ 88,57,57,6498,565326 },          /*     A_PIC88 , element 87     */
	{ 89,57,57,6498,571824 },          /*     A_PIC89 , element 88     */
	{ 90,57,57,6498,578322 },          /*     A_PIC90 , element 89     */
	{ 91,57,57,6498,584820 },          /*     A_PIC91 , element 90     */
	{ 92,57,57,6498,591318 },          /*     A_PIC92 , element 91     */
	{ 93,57,57,6498,597816 },          /*     A_PIC93 , element 92     */
	{ 94,57,57,6498,604314 },          /*     A_PIC94 , element 93     */
	{ 95,57,57,6498,610812 },          /*     A_PIC95 , element 94     */
	{ 96,57,57,6498,617310 },          /*     A_PIC96 , element 95     */
	{ 97,57,57,6498,623808 },          /*     A_PIC97 , element 96     */
	{ 98,57,57,6498,630306 },          /*     A_PIC98 , element 97     */
	{ 99,57,57,6498,636804 },          /*     A_PIC99 , element 98     */
	{ 100,57,57,6498,643302 },          /*     A_PIC100 , element 99     */
	{ 101,57,57,6498,649800 },          /*     A_PIC101 , element 100     */
	{ 102,57,57,6498,656298 },          /*     A_PIC102 , element 101     */
	{ 103,57,57,6498,662796 },          /*     A_PIC103 , element 102     */
	{ 104,57,57,6498,669294 },          /*     A_PIC104 , element 103     */
	{ 105,57,57,6498,675792 },          /*     A_PIC105 , element 104     */
	{ 106,57,57,6498,682290 },          /*     A_PIC106 , element 105     */
	{ 107,57,57,6498,688788 },          /*     A_PIC107 , element 106     */
	{ 108,57,57,6498,695286 },          /*     A_PIC108 , element 107     */
	{ 109,57,57,6498,701784 },          /*     A_PIC109 , element 108     */
	{ 110,57,57,6498,708282 },          /*     A_PIC110 , element 109     */
	{ 111,57,57,6498,714780 },          /*     A_PIC111 , element 110     */
	{ 112,57,57,6498,721278 },          /*     A_PIC112 , element 111     */
	{ 113,57,57,6498,727776 },          /*     A_PIC113 , element 112     */
	{ 114,57,57,6498,734274 },          /*     A_PIC114 , element 113     */
	{ 115,57,57,6498,740772 },          /*     A_PIC115 , element 114     */
	{ 116,57,57,6498,747270 },          /*     A_PIC116 , element 115     */
	{ 117,57,57,6498,753768 },          /*     A_PIC117 , element 116     */
	{ 118,57,57,6498,760266 },          /*     A_PIC118 , element 117     */
	{ 119,57,57,6498,766764 },          /*     A_PIC119 , element 118     */
	{ 120,57,57,6498,773262 },          /*     A_PIC120 , element 119     */
	{ 121,57,57,6498,779760 },          /*     A_PIC121 , element 120     */
	{ 122,57,57,6498,786258 },          /*     A_PIC122 , element 121     */
	{ 123,57,57,6498,792756 },          /*     A_PIC123 , element 122     */
	{ 124,57,57,6498,799254 },          /*     A_PIC124 , element 123     */
	{ 125,57,57,6498,805752 },          /*     A_PIC125 , element 124     */
	{ 126,57,57,6498,812250 },          /*     A_PIC126 , element 125     */
	{ 127,57,57,6498,818748 },          /*     A_PIC127 , element 126     */
	{ 128,57,57,6498,825246 },          /*     A_PIC128 , element 127     */
	{ 129,57,57,6498,831744 },          /*     A_PIC129 , element 128     */
	{ 130,57,57,6498,838242 },          /*     A_PIC130 , element 129     */
	{ 131,57,57,6498,844740 },          /*     A_PIC131 , element 130     */
	{ 132,57,57,6498,851238 },          /*     A_PIC132 , element 131     */
	{ 133,57,57,6498,857736 },          /*     A_PIC133 , element 132     */
	{ 134,57,57,6498,864234 },          /*     A_PIC134 , element 133     */
	{ 135,57,57,6498,870732 },          /*     A_PIC135 , element 134     */
	{ 136,57,57,6498,877230 },          /*     A_PIC136 , element 135     */
	{ 137,57,57,6498,883728 },          /*     A_PIC137 , element 136     */
	{ 138,57,57,6498,890226 },          /*     A_PIC138 , element 137     */
	{ 139,57,57,6498,896724 },          /*     A_PIC139 , element 138     */
	{ 140,57,57,6498,903222 },          /*     A_PIC140 , element 139     */
	{ 141,57,57,6498,909720 },          /*     A_PIC141 , element 140     */
	{ 142,57,57,6498,916218 },          /*     A_PIC142 , element 141     */
	{ 143,57,57,6498,922716 },          /*     A_PIC143 , element 142     */
	{ 144,57,57,6498,929214 },          /*     A_PIC144 , element 143     */
	{ 145,57,57,6498,935712 },          /*     A_PIC145 , element 144     */
	{ 146,57,57,6498,942210 },          /*     A_PIC146 , element 145     */
	{ 147,57,57,6498,948708 },          /*     A_PIC147 , element 146     */
	{ 148,57,57,6498,955206 },          /*     A_PIC148 , element 147     */
	{ 149,57,57,6498,961704 },          /*     A_PIC149 , element 148     */
	{ 150,57,57,6498,968202 },          /*     A_PIC150 , element 149     */
	{ 151,57,57,6498,974700 },          /*     A_PIC151 , element 150     */
	{ 152,57,57,6498,981198 },          /*     A_PIC152 , element 151     */
	{ 153,57,57,6498,987696 },          /*     A_PIC153 , element 152     */
	{ 154,57,57,6498,994194 },          /*     A_PIC154 , element 153     */
	{ 155,57,57,6498,1000692 },          /*     A_PIC155 , element 154     */
	{ 156,57,57,6498,1007190 },          /*     A_PIC156 , element 155     */
	{ 157,57,57,6498,1013688 },          /*     A_PIC157 , element 156     */
	{ 158,57,57,6498,1020186 },          /*     A_PIC158 , element 157     */
	{ 159,57,57,6498,1026684 },          /*     A_PIC159 , element 158     */
	{ 160,57,57,6498,1033182 },          /*     A_PIC160 , element 159     */
	{ 161,57,57,6498,1039680 },          /*     A_PIC161 , element 160     */
	{ 162,57,57,6498,1046178 },          /*     A_PIC162 , element 161     */
	{ 163,37,37,2738,1052676 },          /*     A_PIC163 , element 162     */
	{ 164,37,37,2738,1055414 },          /*     A_PIC164 , element 163     */
	{ 165,37,37,2738,1058152 },          /*     A_PIC165 , element 164     */
	{ 166,37,37,2738,1060890 },          /*     A_PIC166 , element 165     */
	{ 167,37,37,2738,1063628 },          /*     A_PIC167 , element 166     */
	{ 168,57,57,6498,1066366 },          /*     A_PIC168 , element 167     */
	{ 169,57,57,6498,1072864 },          /*     A_PIC169 , element 168     */
	{ 170,57,57,6498,1079362 },          /*     A_PIC170 , element 169     */
	{ 171,57,57,6498,1085860 },          /*     A_PIC171 , element 170     */
	{ 172,57,57,6498,1092358 },          /*     A_PIC172 , element 171     */
	{ 173,40,40,3200,1098856 },          /*     A_PIC173 , element 172     */
	{ 174,40,40,3200,1102056 },          /*     A_PIC174 , element 173     */
	{ 175,40,40,3200,1105256 },          /*     A_PIC175 , element 174     */
	{ 176,40,40,3200,1108456 },          /*     A_PIC176 , element 175     */
	{ 177,40,40,3200,1111656 },          /*     A_PIC177 , element 176     */
};

typedef enum
{
	A_PIC1 = 0,          /*     0     */
	A_PIC2,          /*     1     */
	A_PIC3,          /*     2     */
	A_PIC4,          /*     3     */
	A_PIC5,          /*     4     */
	A_PIC6,          /*     5     */
	A_PIC7,          /*     6     */
	A_PIC8,          /*     7     */
	A_PIC9,          /*     8     */
	A_PIC10,          /*     9     */
	A_PIC11,          /*     10     */
	A_PIC12,          /*     11     */
	A_PIC13,          /*     12     */
	A_PIC14,          /*     13     */
	A_PIC15,          /*     14     */
	A_PIC16,          /*     15     */
	A_PIC17,          /*     16     */
	A_PIC18,          /*     17     */
	A_PIC19,          /*     18     */
	A_PIC20,          /*     19     */
	A_PIC21,          /*     20     */
	A_PIC22,          /*     21     */
	A_PIC23,          /*     22     */
	A_PIC24,          /*     23     */
	A_PIC25,          /*     24     */
	A_PIC26,          /*     25     */
	A_PIC27,          /*     26     */
	A_PIC28,          /*     27     */
	A_PIC29,          /*     28     */
	A_PIC30,          /*     29     */
	A_PIC31,          /*     30     */
	A_PIC32,          /*     31     */
	A_PIC33,          /*     32     */
	A_PIC34,          /*     33     */
	A_PIC35,          /*     34     */
	A_PIC36,          /*     35     */
	A_PIC37,          /*     36     */
	A_PIC38,          /*     37     */
	A_PIC39,          /*     38     */
	A_PIC40,          /*     39     */
	A_PIC41,          /*     40     */
	A_PIC42,          /*     41     */
	A_PIC43,          /*     42     */
	A_PIC44,          /*     43     */
	A_PIC45,          /*     44     */
	A_PIC46,          /*     45     */
	A_PIC47,          /*     46     */
	A_PIC48,          /*     47     */
	A_PIC49,          /*     48     */
	A_PIC50,          /*     49     */
	A_PIC51,          /*     50     */
	A_PIC52,          /*     51     */
	A_PIC53,          /*     52     */
	A_PIC54,          /*     53     */
	A_PIC55,          /*     54     */
	A_PIC56,          /*     55     */
	A_PIC57,          /*     56     */
	A_PIC58,          /*     57     */
	A_PIC59,          /*     58     */
	A_PIC60,          /*     59     */
	A_PIC61,          /*     60     */
	A_PIC62,          /*     61     */
	A_PIC63,          /*     62     */
	A_PIC64,          /*     63     */
	A_PIC65,          /*     64     */
	A_PIC66,          /*     65     */
	A_PIC67,          /*     66     */
	A_PIC68,          /*     67     */
	A_PIC69,          /*     68     */
	A_PIC70,          /*     69     */
	A_PIC71,          /*     70     */
	A_PIC72,          /*     71     */
	A_PIC73,          /*     72     */
	A_PIC74,          /*     73     */
	A_PIC75,          /*     74     */
	A_PIC76,          /*     75     */
	A_PIC77,          /*     76     */
	A_PIC78,          /*     77     */
	A_PIC79,          /*     78     */
	A_PIC80,          /*     79     */
	A_PIC81,          /*     80     */
	A_PIC82,          /*     81     */
	A_PIC83,          /*     82     */
	A_PIC84,          /*     83     */
	A_PIC85,          /*     84     */
	A_PIC86,          /*     85     */
	A_PIC87,          /*     86     */
	A_PIC88,          /*     87     */
	A_PIC89,          /*     88     */
	A_PIC90,          /*     89     */
	A_PIC91,          /*     90     */
	A_PIC92,          /*     91     */
	A_PIC93,          /*     92     */
	A_PIC94,          /*     93     */
	A_PIC95,          /*     94     */
	A_PIC96,          /*     95     */
	A_PIC97,          /*     96     */
	A_PIC98,          /*     97     */
	A_PIC99,          /*     98     */
	A_PIC100,          /*     99     */
	A_PIC101,          /*     100     */
	A_PIC102,          /*     101     */
	A_PIC103,          /*     102     */
	A_PIC104,          /*     103     */
	A_PIC105,          /*     104     */
	A_PIC106,          /*     105     */
	A_PIC107,          /*     106     */
	A_PIC108,          /*     107     */
	A_PIC109,          /*     108     */
	A_PIC110,          /*     109     */
	A_PIC111,          /*     110     */
	A_PIC112,          /*     111     */
	A_PIC113,          /*     112     */
	A_PIC114,          /*     113     */
	A_PIC115,          /*     114     */
	A_PIC116,          /*     115     */
	A_PIC117,          /*     116     */
	A_PIC118,          /*     117     */
	A_PIC119,          /*     118     */
	A_PIC120,          /*     119     */
	A_PIC121,          /*     120     */
	A_PIC122,          /*     121     */
	A_PIC123,          /*     122     */
	A_PIC124,          /*     123     */
	A_PIC125,          /*     124     */
	A_PIC126,          /*     125     */
	A_PIC127,          /*     126     */
	A_PIC128,          /*     127     */
	A_PIC129,          /*     128     */
	A_PIC130,          /*     129     */
	A_PIC131,          /*     130     */
	A_PIC132,          /*     131     */
	A_PIC133,          /*     132     */
	A_PIC134,          /*     133     */
	A_PIC135,          /*     134     */
	A_PIC136,          /*     135     */
	A_PIC137,          /*     136     */
	A_PIC138,          /*     137     */
	A_PIC139,          /*     138     */
	A_PIC140,          /*     139     */
	A_PIC141,          /*     140     */
	A_PIC142,          /*     141     */
	A_PIC143,          /*     142     */
	A_PIC144,          /*     143     */
	A_PIC145,          /*     144     */
	A_PIC146,          /*     145     */
	A_PIC147,          /*     146     */
	A_PIC148,          /*     147     */
	A_PIC149,          /*     148     */
	A_PIC150,          /*     149     */
	A_PIC151,          /*     150     */
	A_PIC152,          /*     151     */
	A_PIC153,          /*     152     */
	A_PIC154,          /*     153     */
	A_PIC155,          /*     154     */
	A_PIC156,          /*     155     */
	A_PIC157,          /*     156     */
	A_PIC158,          /*     157     */
	A_PIC159,          /*     158     */
	A_PIC160,          /*     159     */
	A_PIC161,          /*     160     */
	A_PIC162,          /*     161     */
	A_PIC163,          /*     162     */
	A_PIC164,          /*     163     */
	A_PIC165,          /*     164     */
	A_PIC166,          /*     165     */
	A_PIC167,          /*     166     */
	A_PIC168,          /*     167     */
	A_PIC169,          /*     168     */
	A_PIC170,          /*     169     */
	A_PIC171,          /*     170     */
	A_PIC172,          /*     171     */
	A_PIC173,          /*     172     */
	A_PIC174,          /*     173     */
	A_PIC175,          /*     174     */
	A_PIC176,          /*     175     */
	A_PIC177,          /*     176     */
}PICTURE_NAME;

