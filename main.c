#include <stdio.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>

int main(void) {
	printf("libcurl version: %s\n", curl_version());

	cJSON *json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "message", "hello, world");

	char* jsontext = cJSON_Print(json);
	printf("json text: \n%s\n", jsontext);
	cJSON_free(jsontext);

	cJSON_Delete(json);

	// simple CURL example
	CURL *curl = curl_easy_init();
	if (!curl) {
		fprintf(stderr, "[ERROR] failed to initialize libcurl\n");
		return 1;
	}

	curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");

	CURLcode result = curl_easy_perform(curl);

	if (result != CURLE_OK) {
		fprintf(stderr, "[ERROR] curl error: %s\n", 
			curl_easy_strerror(result));
		return 1;
	}

	curl_easy_cleanup(curl);
	return 0;
}