/******************************************************************************
* File Name: secure_http_client.h
*
* Description: This file contains configuration parameters for the secure HTTP
* client along with the HTML page that the client will host.
*
* Related Document: See README.md
*******************************************************************************
* Copyright 2023, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/


/*******************************************************************************
* Include guard
*******************************************************************************/
#ifndef SECURE_HTTP_CLIENT_H_
#define SECURE_HTTP_CLIENT_H_

/* FreeRTOS header file */
#include "FreeRTOS.h"
#include <task.h>
#include "cy_wcm.h"
#include "cybsp.h"
#include "cy_network_mw_core.h"
#include "cyhal_gpio.h"

#define TEST_INFO( x )                        printf x

/* Wi-Fi Credentials: Modify WIFI_SSID and WIFI_PASSWORD to match your Wi-Fi network
 * Credentials.
 */
#define WIFI_SSID                                "WIFI_SSID"
#define WIFI_PASSWORD                            "WIFI_PASSWORD"

/* Security type of the Wi-Fi access point. See 'cy_wcm_security_t' structure
 * in "cy_wcm.h" for more details.
 */
#define WIFI_SECURITY_TYPE                       CY_WCM_SECURITY_WPA2_AES_PSK

#define MAX_WIFI_RETRY_COUNT                     (3)

#define APP_INFO(x)                              do { printf("Info: "); printf x; } while(0);
#define ERR_INFO(x)                              do { printf("Error: "); printf x; } while(0);

#define PRINT_AND_ASSERT(result, msg, args...)   do                                 \
                                                 {                                  \
                                                     if (CY_RSLT_SUCCESS != result) \
                                                     {                              \
                                                         ERR_INFO((msg, ## args));  \
                                                         CY_ASSERT(0);              \
                                                     }                              \
                                                 } while(0);

#define HTTPS_PORT                               (50007)
#define HTTPS_SERVER_HOST                        "192.168.127.89"
#define TRANSPORT_SEND_RECV_TIMEOUT_MS           (5000)
#define HTTP_GET_BUFFER_LENGTH                   (2048)
#define ASCII_INTEGER_DIFFERENCE                 (48)
#define REQUEST_BODY                             "/myhellomessage=Hello!"
#define HTTP_PATH                                "/"
#define HTTP_GET_PATH_AFTER_PUT                  "/myhellomessage"
#define REQUEST_BODY_LENGTH                      ( sizeof( REQUEST_BODY ) - 1U )

/* Wi-Fi re-connection time interval in milliseconds */
#define WIFI_CONN_RETRY_INTERVAL_MSEC            (1000u)

/*End Range until where the data is expected. Set Set this to -1 if requested range is
 * all bytes from the starting*/
#define HTTP_REQUEST_RANGE_END                   (-1)

/*Start Range from where the server should return.*/
#define HTTP_REQUEST_RANGE_START                 (0)

/*Number of headers in the header list*/
#define NUM_HTTP_HEADERS                         (1)

/*Length of the request header.*/
#define HTTP_REQUEST_HEADER_LEN                  (0)

/* HTTPS Menu for options to select the method from keyboard  */
#define MENU_HTTPS_METHOD                                                           \
        "\n"                                                                        \
        "Please select the index of HTTP method to be tested from below:\n"         \
        "\n"                                                                        \
        "1. HTTPS_GET_METHOD\n"                                                     \
        "2. HTTPS_POST_METHOD\n"                                                    \
        "3. HTTPS_PUT_METHOD\n"                                                     \
        "4. HTTPS_GET_METHOD_AFTER_PUT\n"                                           \

/******************************************************
 *                   Enumerations
 ******************************************************/
/*  HTTP Client supported methods  */
typedef enum
{
    HTTPS_GET_METHOD=1,
    HTTPS_POST_METHOD,
    HTTPS_PUT_METHOD,
    HTTPS_GET_METHOD_AFTER_PUT,
} https_menu_t;

/*******************************************************************************
* Function Prototypes
********************************************************************************/
void https_client_task(void *arg);
cy_rslt_t wifi_connect(void);
#endif /* SECURE_HTTP_CLIENT_H_ */


/* [] END OF FILE */