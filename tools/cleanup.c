#include "cleanup.h"

#include "dist.h"
#include "text.h"
#include "w_catalog_sales.h"
#include "w_store_sales.h"
#include "w_web_sales.h"

void tpcds_cleanup() {
  printf("tpcds_cleanup called; future calls to tpcds functions will fail");
  for (int i = 0; options[i].name != NULL; i++)
  {
    void* p = params[options[i].index];
    if (p) {
      free(p);
    }
  }

  find_dist(NULL, 1);
  gen_text(NULL, 0, 0, 0, 1);

  mk_w_web_sales_master(NULL, 0, 1);
  mk_w_web_sales_detail(NULL, 0, NULL, NULL, 1);
  mk_w_store_sales_master(NULL, 0, 1);
  mk_w_catalog_sales_master(NULL, 0, 1);
}
