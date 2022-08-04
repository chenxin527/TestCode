#include "shell.h"
/**
 * shell的入口
 */
#include <string.h>
void disp_history_cmd(node *head);

void prefix() {
    char cwd[150];

    //取得当前的工作目录
    getcwd(cwd, sizeof(cwd));
    //输出命令提示符
    printf("%s$ ", cwd);
}

int execute(char* buffer) {
	if (buffer == NULL) {
		return 1;
	}
	






	//判断要执行什么命令（包括内置命令和外部命令）
	//进入某个目录
	if(strncmp(buffer, "cd ", 3) == 0) {
        int flag;
	    //将当前工作目录改成参数buffer所指的目录
	    flag = chdir(buffer + 3);
        //目录不存在
	    if (flag == -1) {
	        printf("%s: No such file or directory\n", buffer + 3);
	    }
    }

	//退出shell程序,在shell程序中直接返回0
	else if (strcmp(buffer, "exit") == 0) {
	    return 0;
	}

	//显示历史命令,从栈底元素开始输出
	else if (strcmp(buffer, "!#") == 0) {
	    disp_history_cmd(Log.head);
	}

	//根据前缀查找命令
	else if (buffer[0] == '!' && buffer[1] != '#' ) {
		char cmd[150];
		strcpy(cmd, log_search(&Log, buffer + 1));
		if (strlen(cmd) == 0) {
			printf("No Match\n");
		}
		else {
			log_push(&Log, cmd);
			execute(cmd);
		}
	}

	//列举当前目录下所有子目录和文件
	else if (strcmp(buffer, "ls") == 0) {
            system("dir");
	}

	//执行外部命令
	else {

	}

    return 1;
}

void disp_history_cmd(node *head) {
	if (head->next != NULL) {
		disp_history_cmd(head->next);
	}
	printf("%s\n", head->cmd);
}