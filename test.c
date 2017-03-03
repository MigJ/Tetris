/*
** test.c for  in /home/detroy_j/Documents/delivery/PSU_2016_tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Fri Mar  3 09:25:00 2017 detroy_j
** Last update Fri Mar  3 09:52:42 2017 detroy_j
*/

int	main()
{
  execl("./tetris", "./tetris", "-d", "echo -e '--key-left=\033OA'", 0);
  return (0);
}
