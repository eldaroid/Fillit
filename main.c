int     main(int argc, char **argv)
{
    int fd;

    if (argc != 2)
    {
        ft_printusage();
        return (0);
    }
    fd = open(argv[1], O_RDONLY);
    if(!tetr_read_check(fd))
    {
        ft_print("error");
        return (0);
    }
    close(fd);
    ft = open(argv[1], O_RDONLY);

}