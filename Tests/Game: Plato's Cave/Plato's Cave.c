/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_from_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:30:50 by aaugusto          #+#    #+#             */
/*   Updated: 2025/06/15 17:30:54 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

typedef struct s_game {
    int position;
    int is_finished;
    int has_seen_intro;
} t_game;

void clear_screen()
{
    printf("\033[2J\033[H");
}

void print_banner()
{
    printf(
    "88888888888888888888888888888888888888888888888888888888888888888888888\n"
    "88.._|      | `-.  | `.  -_-_ _-_  _-  _- -_ -  .'|   |.'|     |  _..88\n"
    "88   `-.._  |    |`!  |`.  -_ -__ -_ _- _-_-  .'  |.;'   |   _.!-'|  88\n"
    "88      | `-!._  |  `;!  ;. _______________ ,'| .-' |   _!.i'     |  88\n"
    "88..__  |     |`-!._ | `.| |_______________||.\"'|  _!.;'   |     _|..88\n"
    "88   |``\"..__ |    |`\";. | i|_|MMMMMMMMMMM|_|'| _!-|   |   _|..-|'    88\n"
    "88   |      |``--..|_ | `;!|l|MMoMMMMoMMM|1|.'j   |_..!-'|     |     88\n"
    "88   |      |    |   |`-,!_|_|MMMMP'YMMMM|_||.!-;'  |    |     |     88\n"
    "88___|______|____!.,.!,.!,!|d|MMMo * loMM|p|,!,.!.,.!..__|_____|_____88\n"
    "88      |     |    |  |  | |_|MMMMb,dMMMM|_|| |   |   |    |      |  88\n"
    "88      |     |    |..!-;'i|r|MPYMoMMMMoM|r| |`-..|   |    |      |  88\n"
    "88      |    _!.-j'  | _!,\"|_|M<>MMMMoMMM|_||!._|  `i-!.._ |      |  88\n"
    "88     _!.-'|    | _.\"|  !;|1|MbdMMoMMMMM|l|`.| `-._|    |``-.._  |  88\n"
    "88..-i'     |  _.''|  !-| !|_|MMMoMMMMoMM|_|.|`-. | ``._ |     |``\"..88\n"
    "88   |      |.|    |.|  !| |u|MoMMMMoMMMM|n||`. |`!   | `\".    |     88\n"
    "88   |  _.-'  |  .'  |.' |/|_|MMMMoMMMMoM|_|! |`!  `,.|    |-._|     88\n"
    "88  _!\"'|     !.'|  .'| .'|[@]MMMMMMMMMMM[@] \\|  `. | `._  |   `-._  88\n"
    "88-'    |   .'   |.|  |/| /                 \\|`.  |`!    |.|      |`-88\n"
    "88      |_.'|   .' | .' |/                   \\  \\ |  `.  | `._	|  88\n"
    "88     .'   | .'   |/|  /                     \\ |`!   |`.|    `.  |  88\n"
    "88  _.'     !'|   .' | /                       \\|  `  |  `.    |`.|  88\n"
    "88        			Plato's Cave - Level 1\n"
    "---------------------------------------------------------------------------\n\n");
}

void print_intro()
{
    printf("\nYou awaken in darkness.\n");
    printf("There is a long corridor behind you, but your memory is gone.\n");
    printf("Ahead, a single metal door stands — silent, waiting.\n\n");
    printf("Is the world you knew real? Or were you just watching shadows?\n");
    printf("What lies beyond that door may be truth... or just another illusion.\n");
    printf("This is your choice now: will you open the door?\n\n");
    printf("[press ENTER to begin...]\n");
    getchar();
}

void remove_newline(char *str)
{
    if (!str) return;
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

void process_command(t_game *game, char *command)
{
    if (!command) return;

    if (strcmp(command, "open") == 0)
    {
        printf("You opened the door. A faint light creeps in...\n");
        game->position += 1;
    }
    else if (strcmp(command, "turn") == 0)
    {
        printf("You turned, but the corridor behind you is endless and dark.\n");
    }
    else if (strcmp(command, "exit") == 0)
    {
        printf("You chose to walk away. The shadows embrace you again.\n");
        game->is_finished = 1;
    }
    else
    {
        printf("Unknown command: %s\n", command);
    }
    printf("Press ENTER to continue...");
    getchar();
}

int main(void)
{
    t_game game = {0, 0, 0};
    char *line;

    if (!game.has_seen_intro)
    {
        clear_screen();
        print_banner();
        print_intro();
        game.has_seen_intro = 1;
    }

    while (!game.is_finished)
    {
        clear_screen();
        print_banner();
        printf("Position: %d\n", game.position);
        printf("Available commands: open, turn, exit\n> ");

        line = get_next_line(0);
        if (!line)
            break;
        remove_newline(line);
        process_command(&game, line);
        free(line);
    }

    clear_screen();
    printf("You have left the cave.\nFinal position: %d\n", game.position);
    return 0;
}



