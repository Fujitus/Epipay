##
## Makefile for santa in /home/costa_d/Documents/TEK2/cpp_santa
## 
## Made by Arnaud Costa
## Login   <costa_d@epitech.net>
## 
## Started on  Sun Jan 15 01:56:26 2017 Arnaud Costa
## Last update Wed Apr 19 11:44:22 2017 Arnaud Costa
##

CC			        = g++

RM			        = rm -f

MK			        = mkdir

CPPFLAGS		    = -Iinclude -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system

SRCDIR			    = src/

OBJDIR			    = obj/

NAME		        = epipay

SRCS                = main.cpp  \
                      ui.cpp    \
                      keypad.cpp

OBJS			    = $(addprefix $(OBJDIR), $(SRCS:.cpp=.o))

all:			    $(NAME)

$(NAME):		    $(OBJS)
			        $(CC) -o $(NAME) $(OBJS) $(CPPFLAGS)

$(OBJDIR)%.o:   	$(SRCDIR)%.cpp
			        @$(MK) -p $(OBJDIR)
			        @echo -n "Link " $(notdir $<);
	        	    @$(CC) $(CPPFLAGS) -c $< -o $@ &&						                    \
			        (tput hpa $$(($$(tput cols) - 12)); echo "-=[\033[32m  OK  \033[39m]=-") ||	\
			        (tput hpa $$(($$(tput cols) - 12)); echo "-=[\033[31m FAIL \033[39m]=-")

clean:
			        $(RM) $(OBJS)
			        $(RM) -r $(OBJDIR)

fclean:			    clean
		    	    $(RM) $(NAME)

re:			        fclean all

.PHONY:			    all clean fclean re
