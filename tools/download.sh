times=1
while [ 1 -eq 1 ]; do
  echo  >> ./gitPatches.txt
  echo  >> ./gitPatches.txt
  echo "*********************************************" >> ../gitPatches.txt
  echo "*                                           *" >> ../gitPatches.txt
  echo "*             times: $times                 *" >> ../gitPatches.txt
  echo "*                                           *" >> ../gitPatches.txt
  echo "*********************************************" >> ../gitPatches.txt
  times=$(($times+1))
  top -b -n1 | grep git-svn > tmp.txt
  gitExist=$(cat ./tmp.txt | wc -l)
  if [ $gitExist -eq 0 ]
  then
    git svn fetch >> ../gitPatches.txt &
    sleep 180
    gitSuccess=$(top -b -n1 | grep git-svn | cut -c 1-5)
    if [ $gitSuccess -gt 0 ]
    then
      kill -9 $gitSuccess
    fi
  fi
done

exit 0
