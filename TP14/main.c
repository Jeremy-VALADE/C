#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


static int display_info(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf) {
	printf("%-3s %2d ",
			(tflag == FTW_D) ?   "d"   : (tflag == FTW_DNR) ? "dnr" :
			(tflag == FTW_DP) ?  "dp"  : (tflag == FTW_F) ?   "f" :
			(tflag == FTW_NS) ?  "ns"  : (tflag == FTW_SL) ?  "sl" :
			(tflag == FTW_SLN) ? "sln" : "???",
			ftwbuf->level);
	if (tflag == FTW_NS)
		printf("-------");
	else
		printf("%7jd", (intmax_t) sb->st_size);

	printf("   %-40s %d %s\n",
			fpath, ftwbuf->base, fpath + ftwbuf->base);

	return 0;
}




int main() {
	nftw("../TP13", display_info, 5, FTW_DEPTH);
	return 0;

}
