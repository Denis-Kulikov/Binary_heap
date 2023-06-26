#!/usr/bin/gnuplot

set terminal jpeg font arial 8 size 840,840
set output "data.jpg"
set grid x y y2
set xlabel "Число элементов"
set ylabel "Время(сек.)"
set y2tics

plot 'sort_time.txt' using 1:2 title "tournament sort" with lines,\
	'sort_time.txt' using 1:3 title "Линейная скорость" with lines
