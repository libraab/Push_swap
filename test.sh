make re && ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`; ./push_swap  $ARG

#MAX FOR 500 - 11500
#MAX FOR 100 - 1100
#MAX FOR 5   - 12


#test en printant tout les mouvements
#./test.sh 1 500 
#renvoit le nombre de mouvement
#./test.sh 1 500 | wc -l   