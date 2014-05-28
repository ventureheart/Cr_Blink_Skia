grep msecs ./testdata.txt | cut -d "=" -f2 | cut -c1-8 > data.txt
grep msecs ./testdata_noSSE.txt | cut -d "=" -f2 | cut -c1-8 > data_noSSE.txt
grep "running bench" ./testdata_noSSE.txt | cut -d "]" -f2 > benchname.txt
