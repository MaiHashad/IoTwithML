# SEIS744-Particle-ThingSpeak

This is a lab that I have created for a Masters in Software and Data Science class at hte University of Saint Thomas. In this lab we will covered just a small slice of what is possible with an IoT device sending data to a cloud service. The focus in this lab is on data visualizion and free/low cost tools that allow us to explore and make interesting and useful projects.

The source code is free to use/reuse as you wish. It's largely based off of the tutorials and links which I will include below.

## Data Transfer Mechanisms

Typcially, there are 3 ways in which data can be sent using the [Particle Platform](https://particle.io).

* C Library which you add to your code and uses HTTP/HTTPS
* MQTT library which you again add to your code, but does it over the MQTT protocol
* Particle Webhooks

Each has their own advantange and disadvantage. 

In my lecture, I explain the difeeerences, but to make things easy and free we use [ThingSpeak](https://thingspeak.com) for our data visulization. They offer fre accounts to all and some intersting data additions wfor colleges and universities. Here are links to each tutorials for each method. I have also included exmaple working source code files (.ino) in this repository that mocks out data or uses some basic sensors to send the data.

* [ThingSpeak Library](https://docs.particle.io/reference/device-os/libraries/t/ThingSpeak/)
* [ThingSpeak over MQTT](https://www.mathworks.com/help/thingspeak/use-photon-client-to-publish-to-a-channel.html)
* [ThingSpeak Particle Webhooks](https://docs.particle.io/integrations/webhooks/#how-webhooks-work)

