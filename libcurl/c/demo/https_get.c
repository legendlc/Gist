#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(int argc, char** argv)
{	
	CURL* curl = NULL;
	CURLcode res;

	if (argc < 2)
	{
		exit(0);
	}

	if (curl_global_init(CURL_GLOBAL_SSL) != CURLE_OK)
	{
		exit(1);
	}	

	curl = curl_easy_init();
	if (!curl)
	{
		goto error_exit;
	}

	 curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

	res = curl_easy_perform(curl);
	if (res != CURLE_OK)
	{
		fprintf(stderr, "curl_easy_perform error: %s\n", curl_easy_strerror(res));
		curl_easy_cleanup(curl);

		goto error_exit;
	}

	

	curl_easy_cleanup(curl);

error_exit:
	curl_global_cleanup();

	return 0;
}
