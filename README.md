# HTTPS client

This code example demonstrates the implementation of an HTTPS client with PSoC&trade; 6 MCU and AIROC&trade; CYW43xxx Wi-Fi & Bluetooth&reg; combo chips.

It employs the [HTTPS client](https://github.com/Infineon/http-client) middleware library, which takes care of all the underlying socket connections with the HTTPS server. In this example, the HTTPS client establishes a secure connection with an HTTPS server through an SSL handshake. After the SSL handshake completes successfully, the HTTPS Client can make GET, POST, and PUT requests with the server.

[View this README on GitHub.](https://github.com/Infineon/mtb-example-wifi-https-client)

[Provide feedback on this code example.](https://cypress.co1.qualtrics.com/jfe/form/SV_1NTns53sK2yiljn?Q_EED=eyJVbmlxdWUgRG9jIElkIjoiQ0UyMzc5NTMiLCJTcGVjIE51bWJlciI6IjAwMi0zNzk1MyIsIkRvYyBUaXRsZSI6IkhUVFBTIGNsaWVudCIsInJpZCI6InNkYWsiLCJEb2MgdmVyc2lvbiI6IjEuMC4wIiwiRG9jIExhbmd1YWdlIjoiRW5nbGlzaCIsIkRvYyBEaXZpc2lvbiI6Ik1DRCIsIkRvYyBCVSI6IklDVyIsIkRvYyBGYW1pbHkiOiJQU09DIn0=)


## Requirements

- [ModusToolbox&trade; software](https://www.infineon.com/modustoolbox) v3.0 or later (tested with v3.0)
- Board support package (BSP) minimum required version: 4.0.0
- Programming language: C
- Associated parts: All [PSoC&trade; 6 MCU](https://www.infineon.com/cms/en/product/microcontroller/32-bit-psoc-arm-cortex-microcontroller/psoc-6-32-bit-arm-cortex-m4-mcu) parts, [AIROC&trade; CYW20819 Bluetooth&reg; & Bluetooth&reg; LE system on chip](https://www.infineon.com/cms/en/product/wireless-connectivity/airoc-bluetooth-le-bluetooth-multiprotocol/airoc-bluetooth-le-bluetooth/cyw20819), [AIROC&trade; CYW43012 Wi-Fi & Bluetooth&reg; combo chip](https://www.infineon.com/cms/en/product/wireless-connectivity/airoc-wi-fi-plus-bluetooth-combos/wi-fi-4-802.11n/cyw43012/), [AIROC&trade; CYW4343W Wi-Fi & Bluetooth&reg; combo chip](https://www.infineon.com/cms/en/product/wireless-connectivity/airoc-wi-fi-plus-bluetooth-combos/wi-fi-4-802.11n/cyw4343w)

## Supported toolchains (make variable 'TOOLCHAIN')

- GNU Arm&reg; embedded compiler v10.3.1 (`GCC_ARM`) - Default value of `TOOLCHAIN`
- Arm&reg; compiler v6.16 (`ARM`)
- IAR C/C++ compiler v9.30.1 (`IAR`)


## Supported kits (make variable 'TARGET')


- [PSoC&trade; 6 Wi-Fi Bluetooth&reg; Prototyping Kit](https://www.infineon.com/CY8CPROTO-062-4343W) (`CY8CPROTO-062-4343W`) - Default value of `TARGET`
- [PSoC&trade; 6 Wi-Fi Bluetooth&reg; Pioneer Kit](https://www.infineon.com/CY8CKIT-062-WIFI-BT) (`CY8CKIT-062-WIFI-BT`)
- [PSoC&trade; 62S2 Wi-Fi Bluetooth&reg; Pioneer Kit](https://www.infineon.com/CY8CKIT-062S2-43012) (`CY8CKIT-062S2-43012`)
- [PSoC&trade; 62S1 Wi-Fi Bluetooth&reg; Pioneer Kit](https://www.infineon.com/CYW9P62S1-43438EVB-01) (`CYW9P62S1-43438EVB-01`)
- [PSoC&trade; 62S1 Wi-Fi Bluetooth&reg; Pioneer Kit](https://www.infineon.com/CYW9P62S1-43012EVB-01) (`CYW9P62S1-43012EVB-01`)
- [PSoC&trade; 62S3 Wi-Fi Bluetooth&reg; Prototyping Kit](https://www.infineon.com/CY8CPROTO-062S3-4343W) (`CY8CPROTO-062S3-4343W`)
- [PSoC&trade; 64 "Secure Boot" Wi-Fi Bluetooth&reg; Pioneer Kit](https://www.infineon.com/CY8CKIT-064B0S2-4343W) (`CY8CKIT-064B0S2-4343W`)
- [PSoC&trade; 62S2 Evaluation Kit](https://www.infineon.com/CY8CEVAL-062S2) (`CY8CEVAL-062S2-LAI-4373M2`, `CY8CEVAL-062S2-LAI-43439M2`, `CY8CEVAL-062S2-MUR-43439M2`, `CY8CEVAL-062S2-MUR-4373EM2`)
- [PSoC&trade; 62S2 Wi-Fi Bluetooth&reg; prototyping kit](https://www.infineon.com/CY8CPROTO-062S2-43439) (`CY8CPROTO-062S2-43439`)

## Hardware setup


This example uses the board's default configuration. See the kit user guide to ensure that the board is configured correctly.

**Note:** The PSoC&trade; 6 Bluetooth&reg; LE pioneer kit (CY8CKIT-062-BLE) and the PSoC&trade; 6 Wi-Fi Bluetooth&reg; pioneer kit (CY8CKIT-062-WIFI-BT) ship with KitProg2 installed. The ModusToolbox&trade; software requires KitProg3. Before using this code example, make sure that the board is upgraded to KitProg3. The tool and instructions are available in the [Firmware Loader](https://github.com/Infineon/Firmware-loader) GitHub repository. If you do not upgrade, you will see an error like "unable to find CMSIS-DAP device" or "KitProg firmware is out of date".


## Software setup

Install a terminal emulator if you don't have one. Instructions in this document use [Tera Term](https://ttssh2.osdn.jp/index.html.en).

**Note:** To configure the kit as an HTTPS server, see the [HTTPS server](https://github.com/Infineon/mtb-example-wifi-https-server) code example readme steps.


## Using the code example

Create the project and open it using one of the following:

<details><summary><b>In Eclipse IDE for ModusToolbox&trade; software</b></summary>

1. Click the **New Application** link in the **Quick Panel** (or, use **File** > **New** > **ModusToolbox&trade; Application**). This launches the [Project Creator](https://www.infineon.com/ModusToolboxProjectCreator) tool.

2. Pick a kit supported by the code example from the list shown in the **Project Creator - Choose Board Support Package (BSP)** dialog.

   When you select a supported kit, the example is reconfigured automatically to work with the kit. To work with a different supported kit later, use the [Library Manager](https://www.infineon.com/ModusToolboxLibraryManager) to choose the BSP for the supported kit. You can use the Library Manager to select or update the BSP and firmware libraries used in this application. To access the Library Manager, click the link from the **Quick Panel**.

   You can also just start the application creation process again and select a different kit.

   If you want to use the application for a kit not listed here, you may need to update the source files. If the kit does not have the required resources, the application may not work.

3. In the **Project Creator - Select Application** dialog, choose the example by enabling the checkbox.

4. (Optional) Change the suggested **New Application Name**.

5. The **Application(s) Root Path** defaults to the Eclipse workspace which is usually the desired location for the application. If you want to store the application in a different location, you can change the *Application(s) Root Path* value. Applications that share libraries should be in the same root path.

6. Click **Create** to complete the application creation process.

For more details, see the [Eclipse IDE for ModusToolbox&trade; software user guide](https://www.infineon.com/MTBEclipseIDEUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/docs_{version}/mt_ide_user_guide.pdf*).

</details>

<details><summary><b>In command-line interface (CLI)</b></summary>

ModusToolbox&trade; software provides the Project Creator as both a GUI tool and the command line tool, "project-creator-cli". The CLI tool can be used to create applications from a CLI terminal or from within batch files or shell scripts. This tool is available in the *{ModusToolbox&trade; software install directory}/tools_{version}/project-creator/* directory.

Use a CLI terminal to invoke the "project-creator-cli" tool. On Windows, use the command line "modus-shell" program provided in the ModusToolbox&trade; software installation instead of a standard Windows command-line application. This shell provides access to all ModusToolbox&trade; software tools. You can access it by typing `modus-shell` in the search box in the Windows menu. In Linux and macOS, you can use any terminal application.

The "project-creator-cli" tool has the following arguments:

Argument | Description | Required/optional
---------|-------------|-----------
`--board-id` | Defined in the `<id>` field of the [BSP](https://github.com/Infineon?q=bsp-manifest&type=&language=&sort=) manifest | Required
`--app-id`   | Defined in the `<id>` field of the [CE](https://github.com/Infineon?q=ce-manifest&type=&language=&sort=) manifest | Required
`--target-dir`| Specify the directory in which the application is to be created if you prefer not to use the default current working directory | Optional
`--user-app-name`| Specify the name of the application if you prefer to have a name other than the example's default name | Optional

<br />

The following example clones the "[mtb-example-wifi-https-client](https://github.com/Infineon/mtb-example-wifi-https-client)" application with the desired name "HttpsClient" configured for the *CY8CPROTO-062-4343W* BSP into the specified working directory, *C:/mtb_projects*:

   ```
   project-creator-cli --board-id CY8CPROTO-062-4343W --app-id mtb-example-wifi-https-client --user-app-name HttpsClient --target-dir "C:/mtb_projects"
   ```

**Note:** The project-creator-cli tool uses the `git clone` and `make getlibs` commands to fetch the repository and import the required libraries. For details, see the "Project creator tools" section of the [ModusToolbox&trade; software user guide](https://www.infineon.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/docs_{version}/mtb_user_guide.pdf*).

To work with a different supported kit later, use the [Library Manager](https://www.infineon.com/ModusToolboxLibraryManager) to choose the BSP for the supported kit. You can invoke the Library Manager GUI tool from the terminal using `make library-manager` command or use the Library Manager CLI tool "library-manager-cli" to change the BSP.

The "library-manager-cli" tool has the following arguments:

Argument | Description | Required/optional
---------|-------------|-----------
`--add-bsp-name` | Name of the BSP that should be added to the application | Required
`--set-active-bsp` | Name of the BSP that should be as active BSP for the application | Required
`--add-bsp-version`| Specify the version of the BSP that should be added to the application if you do not wish to use the latest from manifest | Optional
`--add-bsp-location`| Specify the location of the BSP (local/shared) if you prefer to add the BSP in a shared path | Optional

<br />

Following example adds the CY8CPROTO-062-4343W BSP to the already created application and makes it the active BSP for the app:

   ```
   ~/ModusToolbox/tools_3.0/library-manager/library-manager-cli --project "C:/mtb_projects/HttpsClient" --add-bsp-name CY8CPROTO-062-4343W --add-bsp-version "latest-v4.X" --add-bsp-location "local"

   ~/ModusToolbox/tools_3.0/library-manager/library-manager-cli --project "C:/mtb_projects/HttpsClient" --set-active-bsp APP_CY8CPROTO-062-4343W
   ```

</details>

<details><summary><b>In third-party IDEs</b></summary>

Use one of the following options:

- **Use the standalone [Project Creator](https://www.infineon.com/ModusToolboxProjectCreator) tool:**

   1. Launch Project Creator from the Windows Start menu or from *{ModusToolbox&trade; software install directory}/tools_{version}/project-creator/project-creator.exe*.

   2. In the initial **Choose Board Support Package** screen, select the BSP, and click **Next**.

   3. In the **Select Application** screen, select the appropriate IDE from the **Target IDE** drop-down menu.

   4. Click **Create** and follow the instructions printed in the bottom pane to import or open the exported project in the respective IDE.

<br />

- **Use command-line interface (CLI):**

   1. Follow the instructions from the **In command-line interface (CLI)** section to create the application.

   2. Export the application to a supported IDE using the `make <ide>` command.

   3. Follow the instructions displayed in the terminal to create or import the application as an IDE project.

For a list of supported IDEs and more details, see the "Exporting to IDEs" section of the [ModusToolbox&trade; software user guide](https://www.infineon.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/docs_{version}/mtb_user_guide.pdf*).

</details>


## Operation

[HTTPS client](https://github.com/Infineon/mtb-example-wifi-https-client) code example needs a server to communicate. To test this code example, build and program another device with [HTTPS server](https://github.com/Infineon/mtb-example-wifi-https-server) code example to act as an HTTPS server.

**Note:**  Use `policy_single_CM0_CM4_smif_swap.json` policy instead of using the default one "policy_single_CM0_CM4_swap.json" to provision CY8CKIT-064B0S2-4343W device.

1. Connect the board to your PC using the provided USB cable through the KitProg3 USB connector.

2. Open *secure_http_client.h* and modify the `WIFI_SSID`, `WIFI_PASSWORD`, and `WIFI_SECURITY_TYPE` macros to match the credentials of the Wi-Fi network that you want to connect to.

   All possible security types are defined in the `cy_wcm_security_t` structure in the *cy_wcm.h* file.

3. Because this code example uses a self-signed SSL certificate, you need to generate the certificates required by the HTTPS server and client so that they can successfully establish a secure HTTPS connection. Follow the steps provided in a [separate section](#creating-a-self-signed-ssl-certificate) that explains how to generate the certificates.

4. Open the *source/secure_keys.h* file and do the following:

   1. Modify `keyCLIENT_CERTIFICATE_PEM` with the contents from the *mysecurehttpclient.crt* file generated in **Step 3**.
   2. Modify `keyCLIENT_PRIVATE_KEY_PEM` with the contents from the *mysecurehttpclient.key* file generated in **Step 3**.
   3. Modify `keySERVER_ROOTCA_PEM` with the contents from the *rootCA.crt* file generated in **Step 3**.

5. Open the *source/secure_http_client.h* and modify the `#define HTTPS_SERVER_HOST` macro to match the Server IP address that you want to connect to. 

6. Open a terminal program and select the KitProg3 COM port. Set the serial port parameters to 8N1 and 115200 baud.

7. Program the board using one of the following:

   <details><summary><b>Using Eclipse IDE for ModusToolbox&trade; software</b></summary>

      1. Select the application project in the Project Explorer.

      2. In the **Quick Panel**, scroll down, and click **\<Application Name> Program (KitProg3_MiniProg4)**.
   </details>

   <details><summary><b>Using CLI</b></summary>

     From the terminal, execute the `make program` command to build and program the application using the default toolchain to the default target. The default toolchain is specified in the application's Makefile but you can override this value manually:
      ```
      make program TOOLCHAIN=<toolchain>
      ```

      Example:
      ```
      make program TOOLCHAIN=GCC_ARM
      ```
   </details>

8. After programming, the application starts automatically. Verify that the following logs appear on the serial terminal:

   ```
   Info: ===================================
   Info: HTTPS Client
   Info: ===================================

   WLAN MAC Address : 58:D5:0A:A9:CC:27
   WLAN Firmware    : wl0: Jan 30 2020 21:41:53 version 7.45.98.95 (r724303 CY) FWID 01-5afc8c1e
   WLAN CLM         : API: 12.2 Data: 9.10.39 Compiler: 1.29.4 ClmImport: 1.36.3 Creation: 2021-07-18 19:03:20
   WHD VERSION      : 2.6.0.18446 : v2.6.0 : GCC 10.3 : 2023-03-17 21:20:01 +0800
   Info: Wi-Fi initialization is successful
   Info: Join to AP: WIFI_SSID
   Info: Successfully joined Wi-Fi network WIFI_SSID
   Info: Assigned IP address: 192.168.0.12
   Info: successfully connected to https server

   ===============================================================
   Please select the index of HTTPS method to be tested from below:

   1. HTTPS_GET_METHOD
   2. HTTPS_POST_METHOD
   3. HTTPS_PUT_METHOD
   4. HTTP_GET_PATH_FOR_PUT

   ===============================================================
   ```


9. Ensure that your server is connected to the same Wi-Fi access point that you have configured in **Step 2**.

10. If the selected method is `HTTPS_GET_METHOD` then verify that the HTTPS server responds with the following HTML output. This contains the LED status (ON or OFF) of the kit: 

    ```
    HTTP GET GET Request..
   
    Sending Request Headers:
    GET / HTTP/1.1
    User-Agent: mtb-example-wifi-https-client
    Host: 192.168.127.89
    Content-Type: application/x-www-form-urlencoded
    
    Received HTTP response from 192.168.46.89/...
    Response Headers:
    Content-Type: text/html
    Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
    Pragma: no-cache
    Connection: Keep-Alive
    Transfer-Encoding: chunked
    Response Status:
    200

    Response Body:
    <!DOCTYPE html><html><head><title>HTTPS Server Demo</title></head><body><h1>HTTPS Server Demo</h1><form method="get"><fieldset><legend>HTTPS GET</legend><input type="submit" value="Get LED status"/><input type="text" name="led_status" value="OFF" size="3" readonly/></br></br></fieldset></br></form><form method="post"><fieldset><legend>HTTPS POST</legend><input type="submit" name="toggle_led" value="Toggle LED"/></br></br></fieldset></br></form></body></html>
    buffer_len:[2048] headers_len:[172] header_count:[5] body_len:[467] content_len:[0]
    
    Read Headers::
    Connection : Keep-Alive
    Successfully sent GET request to http server
    The http status code is :: 0
    ```
11. If the selected method is `HTTPS_POST_METHOD` then verify that the HTTPS server responds with the following HTML output. The response contains the LED status (ON or OFF) of the last GET request:
    ```
    HTTP POST Request..
    
    Sending Request Headers:
    POST / HTTP/1.1
    User-Agent: anycloud-http-client
    Host: 192.168.46.89
    Connection: keep-alive
    
    Received HTTP response from 192.168.46.89/...
    Response Headers:
    Content-Type: text/html
    Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
    Pragma: no-cache
    Connection: Keep-Alive
    Transfer-Encoding: chunked
    Response Status:
    200

    Response Body:
    <!DOCTYPE html><html><head><title>HTTPS Server Demo</title></head><body><h1>HTTPS Server Demo</h1>
    <form method="get"><fieldset><legend>HTTPS GET</legend><input type="submit" value="Get LED status"/>
    <input type="text" name="led_status" value="OFF" size="3" readonly/></br></br></fieldset></br></form>
    <form method="post"><fieldset><legend>HTTPS POST</legend><input type="submit" name="toggle_led" 
    value="Toggle LED"/></br></br></fieldset></br></form></body></html>
    buffer_len:[2048] headers_len:[172] header_count:[5] body_len:[467] content_len:[0]
    
    Read Headers::
    Connection : Keep-Alive
    Successfully sent GET request to http server
    The http status code is :: 0
    ```
12. If the selected method is `HTTPS_PUT_METHOD` to register a new HTTP resource ("/myhellomessage=Hello!"). The HTTPS server creates a new resource called "myhellomessage".The new resource creation logs you can find in server logs.
   
    ```
    HTTP PUT Request..
   
    Sending Request Headers:
    PUT / HTTP/1.1
    User-Agent: mtb-example-wifi-https-client
    Host: 192.168.127.89
    Content-Type: application/x-www-form-urlencoded
    
    Received HTTP response from 192.168.127.89/...
    Response Headers:
    Content-Type: text/html
    Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
    Pragma: no-cache
    Connection: Keep-Alive
    Transfer-Encoding: chunked
    Response Status :
    200
    Response Body   :
   
    buffer_len:[2048] headers_len:[172] header_count:[5] body_len:[0] content_len:[0]
   
    Read Headers::
    Connection : Keep-Alive
    Successfully sent GET request to http server
    The http status code is :: 0
    ```
13. After that, verify the newly created resource by sending an HTTPS GET request, and the HTTPS server responds with a 'Hello' text message in the response body.
    ```
    HTTP GET FOR PUT method demo begins
   
    Sending Request Headers:
    GET /myhellomessage HTTP/1.1
    User-Agent: mtb-example-wifi-https-client
    Host: 192.168.127.89
    Content-Type: application/x-www-form-urlencoded
    
    Received HTTP response from 192.168.127.89/my...
    Response Headers:
    Content-Type: text/html
    Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
    Pragma: no-cache
    Connection: Keep-Alive
    Transfer-Encoding: chunked
    Response Status :
    200
    Response Body   :
    Hello!
   
    buffer_len:[2048] headers_len:[172] header_count:[5] body_len:[6] content_len:[0]
   
    Read Headers::
    Connection : Keep-Alive
    Successfully send get request to http server
    The http status code is :: 0 
    ```         

## Debugging


You can debug the example to step through the code. In the IDE, use the **\<Application Name> Debug (KitProg3_MiniProg4)** configuration in the **Quick Panel**. For details, see the "Program and debug" section in the [Eclipse IDE for ModusToolbox&trade; software user guide](https://www.infineon.com/MTBEclipseIDEUserGuide).

**Note:** **(Only while debugging)** On the CM4 CPU, some code in `main()` may execute before the debugger halts at the beginning of `main()`. This means that some code executes twice – once before the debugger stops execution, and again after the debugger resets the program counter to the beginning of `main()`. See [KBA231071](https://community.infineon.com/docs/DOC-21143) to learn about this and for the workaround.

## Known issues

An issue has been observed with the multicast domain name system (mDNS) when the device joins the home AP (D-Link DIR-816 and TP-Link Archer C20 APs). To work around this issue, connect the kit to a mobile hotspot if the device reports the following error when joining the AP.

   ```
   Info: Wi-Fi initialization is successful
   Info: Join to AP: WIFI_SSID
   Function whd_wifi_unregister_multicast_address failed at line 2834 checkres = 101580800
   Received buffer request ID: 42 (expectation: 42)
   whd_cdc_send_ioctl is already timed out, drop the buffer
   ```

This issue will be addressed in a future update of this code example.

## Design and implementation

### Resources and settings


**Table 1. Application resources**

 Resource  |  Alias/object     |    Purpose
 :-------- | :-------------    | :------------
 UART (HAL) |cy_retarget_io_uart_obj| UART HAL object used by retarget-io for Debug UART port


<br />

This example uses the Arm&reg; Cortex&reg;-M4 (CM4) CPU of PSoC&trade; 6 MCU to start the HTTPS client task. At device reset, the default Cortex&reg;-M0+ (CM0+) application enables the CM4 CPU and configures the CM0+ CPU to go to sleep.

In this example, the HTTPS client establishes a secure connection with a server through an SSL handshake. During the SSL handshake, the server presents its SSL certificate for verification and verifies the incoming client's identity.


### Creating a self-signed SSL certificate

The HTTPS client demonstrated in this example uses a self-signed SSL certificate. This requires **OpenSSL** which is preloaded in the ModusToolbox&trade; software installation. A self-signed SSL certificate means that there is no third-party certificate issuing authority, commonly referred to as CA, involved in the authentication of the server. Clients connecting to the server must have a root CA certificate to verify and trust the websites defined by the certificate. Only when the client trusts the website, it establishes a secure connection with the HTTPS server.

Do the following to generate a self-signed SSL certificate.

#### Generate an SSL certificate and private key

Run the following script to generate the self-signed SSL certificate and private key.

Before invoking the following command, modify the `OPENSSL_SUBJECT_INFO` macro in the *generate_ssl_certs.sh* file to match your local domain configuration such as  *Country*, *State*, *Locality*, *Organization*, *Organization Unit name*, and *Common Name*. This macro is used by the *openssl* commands when generating the certificate.

```
./generate_ssl_certs.sh
```

This creates the following files:

File                           | Description
-------------------------------|------------
*mysecurehttpclient.crt* | HTTPS client certificate
*mysecurehttpclient.key* | HTTPS client key
*mysecurehttpclient.pfx* | Bundles the HTTPS client certificate and key in PKCS12 format
*rootCA.crt* | HTTPS server rootCA certificate to trust the client
*rootCA.key* | HTTPS server root key used for signing the certificate
*mysecurehttpserver.local.crt* | HTTPS server certificate
*mysecurehttpserver.local.key* | HTTPS server private key

<br />

Configure the HTTPS client to take *mysecurehttpclient.crt* as the certificate, *mysecurehttpclient.key* as the private key, and *rootCA.crt* as the rootCA certificate.

You can either convert the values to strings manually following the format shown in *source/secure_keys.h* or use the HTML utility available [here](https://github.com/Infineon/amazon-freertos/blob/master/tools/certificate_configuration/PEMfileToCString.html) to convert the certificates and keys from PEM format to C string format. Clone the repository from GitHub to use the utility.


## Related resources

Resources  | Links
-----------|----------------------------------
Application notes  | [AN228571](https://www.infineon.com/AN228571) – Getting started with PSoC&trade; 6 MCU on ModusToolbox&trade; software <br />  [AN215656](https://www.infineon.com/AN215656) – PSoC&trade; 6 MCU: Dual-CPU system design
Code examples  | [Using ModusToolbox&trade; software](https://github.com/Infineon/Code-Examples-for-ModusToolbox-Software) on GitHub
Device documentation | [PSoC&trade; 6 MCU datasheets](https://documentation.infineon.com/html/psoc6/bnm1651211483724.html) <br /> [PSoC&trade; 6 technical reference manuals](https://documentation.infineon.com/html/psoc6/zrs1651212645947.html)
Development kits | Select your kits from the [evaluation board finder](https://www.infineon.com/cms/en/design-support/finder-selection-tools/product-finder/evaluation-board)
Libraries on GitHub  | [mtb-pdl-cat1](https://github.com/Infineon/mtb-pdl-cat1) – PSoC&trade; 6 Peripheral Driver Library (PDL)  <br /> [mtb-hal-cat1](https://github.com/Infineon/mtb-hal-cat1) – Hardware Abstraction Layer (HAL) library <br /> [retarget-io](https://github.com/Infineon/retarget-io) – Utility library to retarget STDIO messages to a UART port
Middleware on GitHub  | [psoc6-middleware](https://github.com/Infineon/modustoolbox-software#psoc-6-middleware-libraries) – Links to all PSoC&trade; 6 MCU middleware
Tools  | [Eclipse IDE for ModusToolbox&trade; software](https://www.infineon.com/modustoolbox) – ModusToolbox&trade; software is a collection of easy-to-use software and tools enabling rapid development with Infineon MCUs, covering applications from embedded sense and control to wireless and cloud-connected systems using AIROC&trade; Wi-Fi and Bluetooth&reg; connectivity devices.

<br />

## Other resources


Infineon provides a wealth of data at www.infineon.com to help you select the right device, and quickly and effectively integrate it into your design.

For PSoC&trade; 6 MCU devices, see [How to design with PSoC&trade; 6 MCU - KBA223067](https://community.infineon.com/docs/DOC-14644) in the Infineon Developer community.


## Document history

Document title: *CE237953* - *HTTPS client*

 Version | Description of change
 ------- | ---------------------
 1.0.0   | New code example
<br />

---------------------------------------------------------

© Cypress Semiconductor Corporation, 2023. This document is the property of Cypress Semiconductor Corporation, an Infineon Technologies company, and its affiliates ("Cypress").  This document, including any software or firmware included or referenced in this document ("Software"), is owned by Cypress under the intellectual property laws and treaties of the United States and other countries worldwide.  Cypress reserves all rights under such laws and treaties and does not, except as specifically stated in this paragraph, grant any license under its patents, copyrights, trademarks, or other intellectual property rights.  If the Software is not accompanied by a license agreement and you do not otherwise have a written agreement with Cypress governing the use of the Software, then Cypress hereby grants you a personal, non-exclusive, nontransferable license (without the right to sublicense) (1) under its copyright rights in the Software (a) for Software provided in source code form, to modify and reproduce the Software solely for use with Cypress hardware products, only internally within your organization, and (b) to distribute the Software in binary code form externally to end users (either directly or indirectly through resellers and distributors), solely for use on Cypress hardware product units, and (2) under those claims of Cypress’s patents that are infringed by the Software (as provided by Cypress, unmodified) to make, use, distribute, and import the Software solely for use with Cypress hardware products.  Any other use, reproduction, modification, translation, or compilation of the Software is prohibited.
<br />
TO THE EXTENT PERMITTED BY APPLICABLE LAW, CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH REGARD TO THIS DOCUMENT OR ANY SOFTWARE OR ACCOMPANYING HARDWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  No computing device can be absolutely secure.  Therefore, despite security measures implemented in Cypress hardware or software products, Cypress shall have no liability arising out of any security breach, such as unauthorized access to or use of a Cypress product. CYPRESS DOES NOT REPRESENT, WARRANT, OR GUARANTEE THAT CYPRESS PRODUCTS, OR SYSTEMS CREATED USING CYPRESS PRODUCTS, WILL BE FREE FROM CORRUPTION, ATTACK, VIRUSES, INTERFERENCE, HACKING, DATA LOSS OR THEFT, OR OTHER SECURITY INTRUSION (collectively, "Security Breach").  Cypress disclaims any liability relating to any Security Breach, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any Security Breach.  In addition, the products described in these materials may contain design defects or errors known as errata which may cause the product to deviate from published specifications. To the extent permitted by applicable law, Cypress reserves the right to make changes to this document without further notice. Cypress does not assume any liability arising out of the application or use of any product or circuit described in this document. Any information provided in this document, including any sample design information or programming code, is provided only for reference purposes.  It is the responsibility of the user of this document to properly design, program, and test the functionality and safety of any application made of this information and any resulting product.  "High-Risk Device" means any device or system whose failure could cause personal injury, death, or property damage.  Examples of High-Risk Devices are weapons, nuclear installations, surgical implants, and other medical devices.  "Critical Component" means any component of a High-Risk Device whose failure to perform can be reasonably expected to cause, directly or indirectly, the failure of the High-Risk Device, or to affect its safety or effectiveness.  Cypress is not liable, in whole or in part, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any use of a Cypress product as a Critical Component in a High-Risk Device. You shall indemnify and hold Cypress, including its affiliates, and its directors, officers, employees, agents, distributors, and assigns harmless from and against all claims, costs, damages, and expenses, arising out of any claim, including claims for product liability, personal injury or death, or property damage arising from any use of a Cypress product as a Critical Component in a High-Risk Device. Cypress products are not intended or authorized for use as a Critical Component in any High-Risk Device except to the limited extent that (i) Cypress’s published data sheet for the product explicitly states Cypress has qualified the product for use in a specific High-Risk Device, or (ii) Cypress has given you advance written authorization to use the product as a Critical Component in the specific High-Risk Device and you have signed a separate indemnification agreement.
<br />
Cypress, the Cypress logo, and combinations thereof, WICED, ModusToolbox, PSoC, CapSense, EZ-USB, F-RAM, and Traveo are trademarks or registered trademarks of Cypress or a subsidiary of Cypress in the United States or in other countries. For a more complete list of Cypress trademarks, visit www.infineon.com. Other names and brands may be claimed as property of their respective owners.
