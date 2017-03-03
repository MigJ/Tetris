/*
** test.c for  in /home/detroy_j/Documents/delivery/PSU_2016_tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Fri Mar  3 09:25:00 2017 detroy_j
** Last update Fri Mar  3 09:29:23 2017 detroy_j
*/

int	main()
{
  execl("./tetris", "./tetris", "-d", "--key-left='\033[A'", 0);
  return (0);
}
