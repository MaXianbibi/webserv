/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:16:52 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/14 18:08:55 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/webserv.hpp"

std::vector<std::pair<std::string, std::string> > req::mime;

void req::innitMime(void)
{
	std::string list(".aac audio/aac .abw application/x-abiword .arc application/octet-stream .avi video/x-msvideo .azw application/vnd.amazon.ebook .bin application/octet-stream .bmp image/bmp .bz application/x-bzip .bz2 application/x-bzip2 .csh application/x-csh .css text/css .csv text/csv .doc application/msword .docx application/vnd.openxmlformats-officedocument.wordprocessingml.document .eot application/vnd.ms-fontobject .epub application/epub+zip .gif image/gif .htm text/html .html text/html .ico image/x-icon .ics text/calendar .jar application/java-archive .jpeg image/jpeg .jpg image/jpeg .js application/javascript .json application/json .mid audio/midi .midi audio/midi .mpeg video/mpeg .mpkg application/vnd.apple.installer+xml .odp application/vnd.oasis.opendocument.presentation .ods application/vnd.oasis.opendocument.spreadsheet .odt application/vnd.oasis.opendocument.text .oga audio/ogg .ogv video/ogg .ogx application/ogg .otf font/otf .png image/png .pdf application/pdf .ppt application/vnd.ms-powerpoint .pptx application/vnd.openxmlformats-officedocument.presentationml.presentation .rar application/x-rar-compressed .rtf application/rtf .sh application/x-sh .svg image/svg+xml .swf application/x-shockwave-flash .tar application/x-tar .tif image/tiff .tiff image/tiff .ts application/typescript .ttf font/ttf .vsd application/vnd.visio .wav audio/x-wav .weba audio/webm .webm video/webm .webp image/webp .woff font/woff .woff2 font/woff2 .xhtml application/xhtml+xml .xls application/vnd.ms-excel .xlsx application/vnd.openxmlformats-officedocument.spreadsheetml.sheet .xml application/xml .xul application/vnd.mozilla.xul+xml .zip application/zip .3gp video/3gpp .3g2 video/3gpp2 .7z application/x-7z-compressed");
	std::vector<std::string> mf = split(list, ' ');
	req::mime.resize(67);
	for (size_t i = 0; i < mf.size(); i += 2)
		mime[i] = std::make_pair(mf[i], mf[i + 1]);
}

int main(void)
{
	std::vector<u_int16_t> port;
	port.push_back(8080);
	port.push_back(8081);
	port.push_back(8082);
	port.push_back(2);
	server a(port);

	req::innitMime();
	
	while (1)
		for (u_int16_t i = 0; i < a.vServer.size(); i++)
			a.vServer[i].run();
}