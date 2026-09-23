#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>

int main(void) {
	printf("libcurl version: %s\n", curl_version());

	cJSON *json = cJSON_CreateObject();
	if (!json) {
		fprintf(stderr, "[ERROR] failed to create JSON object\n");
		return 1;
	}
	if (!cJSON_AddStringToObject(json, "message", "hello, world")) {
		fprintf(stderr, "[ERROR] failed to add string to JSON object\n");
		return 1;
	}

	char* jsontext = cJSON_Print(json);
	if (!jsontext) {
		fprintf(stderr, "[ERROR] failed to create print buffer for JSON object\n");
	}
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
		fprintf(stderr, "[ERROR] curl error: %s\n", curl_easy_strerror(result));
		curl_easy_cleanup(curl);
		return 1;
	}

	curl_easy_cleanup(curl);
	return 0;
}