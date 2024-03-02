#!/bin/bash
if [ $# != 2 ]; then
	echo "parameter number is $#, parameter number error!"
	echo -e "cfg_to_h.cfg [cfgfile] [hfile]\n"
	exit 1
fi
echo "cfg_to_h.cfg"
echo "$@"
echo "$1"
echo "$2"

src_cfgfile=$1
hfile=$2
cfgfile=./tmp_nvitem.cfg

if [ "${src_cfgfile##*.}"x != "cfg"x ]; then
	echo "parameter 1 is $src_cfgfile, it's must is a cfg file path name!"
	exit 2
fi
if [ ! -f "$src_cfgfile" ]; then
	echo "the cfg file does not exit!"
	exit 2
fi

if [ "${hfile##*.}"x != "h"x ]; then
	echo "parameter 2 is $hfile, it's must is a h file path name!"
	exit 2
fi
if [ -f "$hfile" ]; then
	echo "rm $hfile!"
	rm $hfile
fi

cat $src_cfgfile |tr -d '\r' > $cfgfile
echo "#ifndef __NV_MERGE_CFG_H__" > $hfile
echo "#define __NV_MERGE_CFG_H__" >> $hfile
echo -e '\n' >> $hfile
echo "/*" >> $hfile
echo " * This h file is automatically generated. Please do not modify anything in this file." >> $hfile
echo " */" >> $hfile
echo -e '\n' >> $hfile
echo "typedef unsigned char        BOOLEAN;" >> $hfile
echo "typedef unsigned char        uint8;" >> $hfile
echo "typedef unsigned short       uint16;" >> $hfile
echo "typedef unsigned int         uint32;" >> $hfile
echo "typedef signed char          int8;" >> $hfile
echo "typedef signed short         int16;" >> $hfile
echo "typedef signed int           int32;" >> $hfile
echo "#define TRUE     1" >> $hfile
echo "#define FALSE    0" >> $hfile
echo "#define NV_SIZE_MAX    0x80000" >> $hfile
echo "#define BACKUP_NUM_MAX   100" >> $hfile
echo "#define INVALID_ID   0xffff" >> $hfile
echo -e '\n' >> $hfile
echo "typedef struct _NVITEM_CFG { /* Information of every item */" >> $hfile
echo "    char               name[50];" >> $hfile
echo "    unsigned int       id;" >> $hfile
echo "} NVITEM_CFG;" >> $hfile
echo -e '\n' >> $hfile
echo "NVITEM_CFG nv_cfg[100] = {" >> $hfile
while read LINE || [[ -n ${LINE} ]];
do
	if [ -n "$LINE" ]; then
		if [ ${LINE:0:1} != "\0" -a ${LINE:0:1} != "#" ]; then
			str_line=(${LINE//,/})
			printf "{\"%s\", %#x},\n" ${str_line[0]} ${str_line[1]} >> $hfile
		fi
	fi
done  < $cfgfile
echo "};" >> $hfile
echo -e "\n" >> $hfile
echo "#endif //__NV_MERGE_CFG_H__" >> $hfile


echo "rm $cfgfile!"
rm $cfgfile
echo  "h file to CFG file conversion Complete!"

