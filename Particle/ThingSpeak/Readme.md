## Particle-ThingSpeak

This is a lab is created by Prof. Justin Grammens for a Masters in Software and Data Science class at hte University of Saint Thomas. In this lab we cover just a small slice of what is possible with an IoT device sending data to a cloud service. The focus in this lab is on data visualizion and free/low cost tools that allow us to explore and make interesting and useful projects.

The source code is free to use/reuse. It's largely based off of the tutorials and links included below.

## Data Transfer Mechanisms

Typcially, there are 3 ways in which data can be sent using the [Particle Platform](https://particle.io).

* C Library which you add to your code and uses HTTP/HTTPS
* MQTT library which you again add to your code, but does it over the MQTT protocol
* Particle Webhooks

Each has their own advantange and disadvantage. 

To make things easy and free we use [ThingSpeak](https://thingspeak.com) for our data visulization. They offer free accounts to all and some intersting data additions for colleges and universities. Here are links to each tutorials for each method.

* [ThingSpeak Library](https://docs.particle.io/reference/device-os/libraries/t/ThingSpeak/)
* [ThingSpeak over MQTT](https://www.mathworks.com/help/thingspeak/use-photon-client-to-publish-to-a-channel.html)
* [ThingSpeak Particle Webhooks](https://docs.particle.io/integrations/webhooks/#how-webhooks-work)

