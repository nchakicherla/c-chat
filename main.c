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
}