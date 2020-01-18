#!/bin/bash

#oblicz liczbe procesow ktore zuzyly wiecej niz N sekund procesora
# proste
czas=0
if [[ $# = 0 ]]; then
	echo "prosze podac czas!"
	read czas
else
	czas=$1
fi
	list=$(ps --no-headers -eo times | awk "{ if (\$1 > $czas) print \$1 }" | wc -l)
	echo $list
exit 0
# monitoruj sume RSS dla procesow wszystkich uzytkownikow
users=""
sum=0
trap 'echo "elo"; exit 123' SIGINT
if [[ $# = 0 ]]; then
        users=$USER
else
    	users=$*
fi

        while [[ 1 ]]; do
                for user in $users; do
                		echo $user
                        sum=0
                        list=$(ps --no-headers -eo user,rss | awk -F' ' '{print $2}')
                        echo $list
                        
                        for proc in $list; do
                        		echo $proc
                                sum=$(($sum + $proc))
                        done
                        echo "[ USER: $user, RSS: $sum] - "
                done
                sleep 3
        done

exit 0



#monitoruj sume RSS procesow danego uzytkownika
if [[ $# = 0 ]]; then
        echo "nieprawdilowa liczba argumentow"
        exit 1
elif [[ $# > 1 ]]; then
        echo "nieprawidlowa liczba argumentow"
        exit 1
else
    	while [[ 1 ]]; do
                suma=0
                procesy=$(ps --no-headers -eo user,rss | grep ^"$1" | awk '{print $2}')
                for proc in $procesy; do
                        suma=$(($suma + $proc))
                done
                echo "RSS uzytkownika $1 wynosi $suma"
                sleep 2
        done
fi
exit 0


#wypisz opisy zalogowanych użytkowników 

users=$(who | awk -F' ' '{ print $1 }')
echo $users
for usr in $users; do
	echo "sprawdzany usr: $usr"
	echo $(cat /etc/passwd | awk -F: "{ if (\$1 == \"$usr\") print \$5}")
done
exit 0



# oblicz sumę rozmiarów plików regularnych w podanych katalogach 
katalog=""
suma=0
suma_w_katalogu=0
if [[ $# = 0 ]]; then
	echo "Podaj katalog"
	read katalog
else
	katalog=$*
fi
for dir in $katalog; do
	list=$(ls $dir -al | grep ^- | awk -F' ' '{print $5}')
	for all in $list; do
		suma_w_katalogu=$(($suma_w_katalogu + $all))
	done
	echo "Suma w katalogu $dir: $suma_w_katalogu"
	suma=$(($suma + $suma_w_katalogu))
	echo "Aktualnia suma: $suma"
	suma_w_katalogu=0
done
echo "Sumarycznie we wszystkich katalogach: $suma"
exit 0



#wypisz nazwy uzytkownikow o podanych uid'ach
if [[ $# = 0 ]]; then
	echo "brak argumentow"
	exit 1
fi

for i in $*; do
	user=$(cat /etc/passwd | awk -F':' "{ if (\$3 == $i) print \$1,\$3}")
		echo $user
		user=""
	fi
done

exit 0




#oblicz liczbe i sume rozmiarow plikow regularnych w podanym katalogu 
if [[ $# > 1 ]]; then
        echo "nieprawidlowa liczba arg"
        exit 1
elif [[ $# = 1 ]]; then
        if [[ ! -d $1 ]]; then
                echo "podany argument nie jest katalogiem"
                exit 2
        else
                reg_files=`find $1 -maxdepth 1 -type f | wc -l`
                size=0   
                #for a in $(ls $1 - al | grep -E ^d | );do
                #done
        fi
fi


#Oblicz liczbę plików regularnych w podanych katalogach.
if [[ $# = 0 ]]; then
	echo "reg_files in $HOME: `find ~ -maxdepth 1 -type f | wc -l`"
	exit 0

else
	for i in $*; do 
		if [[ -d $i ]]; then
			echo "reg_files in $i: `find $i -maxdepth 1 -type f | wc -l`"

		else 
			echo "$i nie jest katalogiem"
		fi
	done
	exit 0
fi




exit 0
# find liczy liczbę katalogów w katalogu wraz z 
if [[ $# = 0 ]]; then
	#wtedy sprawdzamy w katalogu bieżącym 
	reg_files=`find $(pwd) -maxdepth 1 -type f | wc -l`
	dir=`find $(pwd) -maxdepth 1 -type d | wc -l`
	sym_links=`find $(pwd) -maxdepth 1 -type l | wc -l`
	echo "sprawdzany katalog: `pwd`"
	echo "pliki regularne: $reg_files  katalogi: $dir  dowiazania symboliczne: $sym_links"
	exit 0
elif [[ $# > 1 ]]; then
	reg_files=`find $1 -maxdepth 1 -type f | wc -l`
	dir=`find $1 -maxdepth 1 -type d | wc -l`
	sym_links=`find $1 -maxdepth 1 -type l | wc -l`
	echo "sprawdzany katalog: $1"
	echo "pliki regularne: $reg_files  katalogi: $dir  dowiazania symboliczne: $sym_links"
	switch
	while [[ $# > 0 ]]; do
		echo "Parametr nadliczbowy: $1"
		switch
	done
	exit 0
else
	reg_files=`find $1 -maxdepth 1 -type f | wc -l`
	dir=`find $1 -maxdepth 1 -type d | wc -l`
	sym_links=`find $1 -maxdepth 1 -type l | wc -l`
	echo "sprawdzany katalog: $1"
	echo "pliki regularne: $reg_files  katalogi: $dir  dowiazania symboliczne: $sym_links"
	exit 0
fi


exit 0
#oblicz liczbę plików regularnych w podanym katalogu
if [[ $# = 0 ]]; then 
	reg_files=`find -maxdepth 1 -type f | wc -l`
	echo "liczba plikow regularnych w katalogu domowym: $reg_files"
	exit 0
elif [[ $# > 1 ]]; then
	echo "podano zbyt wiele argumentow"
	exit 1
elif [[ ! -d $1 ]]; then
	echo "podany argument nie jest katalogiem!"
	exit 2
else
	reg_files=`find $1 -maxdepth 1 -type f | wc -l`
	echo "Liczba plikow regularnych w katalogu $1 wynosi: $reg_files"
	exit 0
fi
exit 0
