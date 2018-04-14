#include "../lib/shelly.h"

int main(void)
{
	char *line = NULL;
	char **tokens;
	size_t len = 0;
	pid_t child;

	while (1)
	{
		pstring("$ ");
		getline(&line, &len, stdin);
		strip_line(line);
		tokens = get_tokens(line);
		child = fork();
		run_cmd(tokens, child);
	}
	free(line);
	return (0);
}
