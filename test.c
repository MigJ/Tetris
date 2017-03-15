int	main()
{
  execl("./tetris", "./tetris", "-d", "-kl", "\033E\034\033\034R", 0);
  return (0);
}
