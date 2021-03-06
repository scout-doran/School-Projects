Version 0.8.7.5 (September 14, 2019)
-----
* Randomness added to Earth resource consumption.
* "Load All Cargo" order added. This order can be given to a unit by using the main menu, colony dialog context menu, or by the shortcut Ctrl+Y.
* Earth tax added to unit sales.
* Updates in colony dialog panel.
* Updated population decrease ratio to be more realistic.
* Transporters' movement points are not reset when loading unloading.
* A spaceship cannot be launched if the colony it is in is missing a starport or has a starport that is disabled.
* A spaceship cannot land if target colony is missing a starport or has a starport that is disabled. It will wait in Mars orbit until starport is enabled.
* "Unable to land spaceship" message added.
* Bugs fixed.
 - Colony improvement image bug after enabling by assigning colonists.
 - Colony improvement remove bugs fixed.
 * Help pages updated.

Version 0.8.7.4 (August 18, 2019)
-----
* Player confirmation is needed to launch empty spaceships from Mars.
* Message history dialog updated.
* An information message is displayed in turn 6 about financing of the first starport.
* An information message is displayed in turn 18 about financing of a colonizer.
* Major balance update in colony improvement and unit costs.
* A button is added to Earth dialog to finance maximum possible colonists for the selected unit.
* Colony population increase/decrease ratios updated.
* Mission rewards are increased to 20000, 40000 and 60000 from 10000, 20000 and 40000.
* Updates in some mission objectives.
 - Population mission objectives are now 500, 1000 and 2000.
 - Number of roads for 3rd tile improvement mission is increased to 40.
* Production and upkeep costs modified for some colony improvements. Buying vs. building margin decreased.
* Energy cost of steel, glass and chemicals increased.
* Food donation random event added.
* Spaceship navigation error random event added.
* Toolshop colony improvement added. Improvement build order is Toolshop, Workshop, Factory.
* Resource cost added to colony improvements.
* "Home" key now focuses on first colony.
* Some bugs fixed.
 - Audio problems
 - Tiles used by other settlements
 - Auto fertilization
 - AI player gifts
 - Engineer and colonizer tool tip
 - Nation bonus tool tip
* Help pages updated.

Version 0.8.7.3 (March 26, 2019)
-----
* Removed close button from main menu.
* If user wants to quit the map editor and there is an unsaved map, a warning message is displayed.
* Brush, Tools and View menu are disabled if there is no map in editor.
* Help pages updated.

Version 0.8.7.2 (September 2, 2017)
-----
* Save / Load dialogs customized to display info on save file contents. Delete button added to dialogs.
* Earth dialog info text updated.
* Demographics dialog resized.
* Unit movement animation bugs fixed.
* Earth economy updated.
* Italian sell price bonus reduced to %5 from %10.
* Spaceship debris collection bug fixed.
* Export resource mission updated to allow multiple resources.
 - Iron, Silica or Minerals can be exported to complete mission.
 - Target quantities updated to 10000, 20000 and 30000
* Spaceship debris image updated.
* Meteor fall random event added. This random event distributes valuable elements around a random coordinate.
* A small road image is painted even if tile has no adjacent tiles having roads.
* Display player command status bug fixed.
* Console is opened with " (double quote) character.
* Following console commands added: add, bye, clear, close, cls, disp, display, earth, exit, explore, help, pop, population, quit, remove, rm, setturn, wealth
* Audio player fixed.

Version 0.8.7.1 (April 2, 2016)
-----
* Clear tile vegetation mission added.
* Missions dialog updated. Completed missions are displayed green and failed missions are displayed red.
* Number of suggested players for maps updated.
* Minimum allowed players for maps is set to 2.
* Colony production buy update bug fixed.
* Cost to build militia is set to 40 colonists and 120 gauss rifles.
* Consumption priority updated for resources that are required for colony population. Related bug fixed.

Version 0.8.7.0 (February 27, 2016)
-----
* Diplomacy dialog updated.
 - Offer alliance, offer peace and declare war added.
 - Offer gift option added.
 - Exchange maps option added.
 - No negotiation allowed with the expeditionary force.
* Diplomatic relations start turn added, related information dialog added.
* Diplomatic relations normalization per turn added.
* 1 militia are added to startup units.
* AI player properties added. Player save data bug fixed.
* End turn button dimensions updated.
* Image manager updated.
* Expeditionary force info dialog resized.
* Expeditionary force update dialog resized.
* Map editor fixed.
* Tiny and giant Mars maps added.
* Terrain and vegetation types in pre-made Mars maps are standardized.
 - Plains 25%
 - Wasteland 20%
 - Swamp 15%
 - Desert 10%
 - Hills 10%
 - Tundra 5%
 - Crater 5%
 - Ice 5%
 - Mountains 4%
 - Chasm & Misty mountains 1%
* Vegetation types in pre-made Mars maps are standardized. Total vegetation is set to 35%.
 - Mutated cactus forest 15%
 - Giant mushrooms 13%
 - Martian scrub forest 3%
 - Martian taiga 4%
* Logging added.

Version 0.8.6.9 (June 27, 2015)
-----
* Energy is added to resources that are required for colony growth.
* New colonies get a free solar panel.
* In colony dialog vital resources are displayed in different colors.
 - Green, if colony is producing more than it is consuming.
 - Yellow, if colony is producing less than it is consuming.
 - Red, if colony is producing less than it is consuming and remaining quantity is not enough for next turn.
* Steel works adds 5000 to storage capacity for iron and steel.
* Steel factory adds 10000 to storage capacity for iron and steel.
* Glass works adds 5000 to storage capacity for silica and glass.
* Glass factory adds 10000 to storage capacity for silica and glass.
* Chemical works adds 5000 to storage capacity for minerals and chemicals.
* Chemical plant adds 10000 to storage capacity for minerals and chemicals.
* Tile improvement mission values updated.
* Population mission values updated.
* AI player logic updated.
 - Steel, glass and chemicals are produced in colonies and exported.
 - Colonists from Earth board spaceships.
 - Excess energy is sold to Earth.
 - Tries to complete all mission types.
* Configuration update on log files.
* Minor updates in XML configuration.
* Third level missions' rewards are increased to 40,000 credits from 30,000 credits.
* Militia barracks removed. Infantry barracks added.
* Militia barracks prerequisite removed from militia unit. 200 population prerequisite added to militia unit.
* Logging added.

Version 0.8.6.8 (March 15, 2015)
-----
* Property added to transporters to carry colonizers.
* Load / Unload buttons added to units in colony management dialog.
* Unload colonists added to "Go to tile..." menu.
* Number of on board colonists is displayed in main map & colony unit info panel.
* Contained units are displayed in main map active unit info panel.
* Unload cargo bug fixed.
* Colonizer weight for carrying units increased.
* Colony dialog unit selection method (click or hover) added to preferences. Default set to click.
* Cargo of units that are traveling between Mars and Earth is displayed as pop-ups when mouse is hovered above them.
* In colony dialog, if a tile currently used by another colony belonging to the same player is selected, an option is displayed to remove current workforce.
* Minor updates in colony management dialog.

Version 0.8.6.7 (March 1, 2015)
-----
* Bug #228 : "Unit paint in unexplored areas" fixed.
* Bug #229 : "Units not painted in newly explored areas" fixed.
* Vegetation removal bug fixed.
* Player's secondary color is also used in painting borders.
* AI player playing progress bar & info added.
* Transform terrain order not updated on map bug fixed.
* New colony names added to nations.
* Nation colors updated.
* Territory borders bug fixed.
* Go to tile & execute order bug fixed.
* Logging added.

Version 0.8.6.6 (January 17, 2015)
-----
* Custom map crash bug fixed.
* Bug #226 : "Unit orders displayed for other player's units" is fixed.
* Bug #227 : "Colony dialog displayed for other player's colonies" is fixed.

Version 0.8.6.5 (January 11, 2015)
-----
* Territory borders and related preference added.
* Jumping animation bug in unit movement fixed.
* Performance tuning in unit animation.
* Inactive colonizer check bug for player defeat is fixed.
* Game frame repaint updated.
* Version info text editable property set to false in about dialog.
* Map grid color set to white.
* "Sentry" text changed to "Sentry / Sleep".
* "Colonists returning to Earth" event will not be triggered in the first 4 years (48 turns).
* Logging added.

Version 0.8.6.4 (November 10, 2014)
-----
* Auto managed resource XML serialization bug fixed.
* Vegetation clearing bug fixed.
* Unnecessary focus on AI player bug fixed.
* "Plains" type tiles' probability increased in custom maps.
* Player nation flags updated.
* Vegetation in medium Mars map increased.

Version 0.8.6.3 (November 2, 2014)
-----
* Workforce manager in colony dialog is updated to display tiles that are not available for workforce assignment because they are being used by another colony.
* Following sounds added :
  - Unit movement
  - Colony improvement enable
  - Colony improvement disable
* "Sound" tab added to Preferences dialog.
  - Unit movement sound
  - Spaceship launch sound
  - Resource transfer sound
  - Wealth transfer sound
  - Colony improvement enable
  - Colony improvement disable
* Preferences dialog dimensions updated.
* Mini map redesigned.
* Mini map zoom bug fixed.
* Mini map tile display type (color or image) preference added.
* Following images updated:
  - Water pump
  - Water extractor
  - Hydrogen collector
  - Granary
  - Food silo
  - Solar panel
  - Solar array
  - Starport
  - Wall
  - Defense turrets

Version 0.8.6.2 (October 18, 2014)
-----
* Unit produced in colony message added.
* Double message bug fixed.
* Added preference "Display player flags on units", which is off by default but when selected, this option will add flags to units on the main map.
* "Factory Production Halted" message added, that is sent when a factory runs out of a required resource.
* Optional automation is added to scouts.
* Preferences dialog dimensions updated.
* Infantry unit images updated.
* Full screen display mode bug fixed.
* Colony rename dialog redesigned.
* Updates made in configuration.
* Some code efficiency modifications made.

Version 0.8.6.1 (October 2, 2014)
-----
* Magnesium and gauss rifle resources added to colony manager dialog resources tab.
* Militia unit images updated.
* Infantry unit images updated.
* Transformable tile types bug fixed.
* Logging added to AI player decision model.

Version 0.8.6.0 (September 28, 2014)
-----
* "Hover-car parts" resource removed.
* "Gauss rifle" resource added.
* "Rifle workshop" colony improvement added.
* "Militia" unit type added. Related images added.
* Militia help page added.
* "Infantry" unit type added to the Expeditionary force. Related images added.
* Population cost added to some unit types.
* Resource cost added to some unit types. 
 - Colonizers require steel.
 - Militia & mech require gauss rifles.
 - Spaceships require spaceship parts.
* Population and resource cost info is added to colony production queue management panel.
* Expeditionary force will land in 3 separate waves instead of 1.
* Expeditionary force Earth to Mars preparation & arrival time is increased to 12 from 8.
* Current expeditionary force information dialog size updated.
* Expeditionary force landed dialog image updated.
* Expeditionary force landed dialog size updated.
* Warning messages will be displayed if a colony has enough production points but not enough population or resource quantity for its current production.
* Auto save turns bug fixed in Preferences dialog.
* Unit attack dialog width increased.
* Duration is set to "N/A" for collect debris mission.
* Bug #222 : "Remove player bug" is fixed.
* Mech build cost set to 12.000 production points.
* Earth prices in Earth dialog are updated after buying or selling.
* Unit upkeep costs are reduced and fixed to 1% of production price.
* 1000 food is automatically added to new colonies.
* When first colony is built on a tile containing a collectable, the collectable is automatically delivered to that colony.
* Mars and Earth icons are added to display orbit and Earth buttons in the main game frame.
* Play sound bug fixed.
* Updates made in XML serialization of units.
* Logging added.

Version 0.8.5.9 (August 27, 2014)
-----
* Bug fixes for version 0.8.5.8
* Purchase colonists bug fixed.
* Custom game initialization bug fixed.

Version 0.8.5.8 (August 23, 2014)
-----
* Simple logic added to AI players. AI players will now:
 - Manage food & water production. Colonists will not starve or die of thirst.
 - Scout the map.
 - Mine exportable resources and sell them to Earth.
 - Receive support from Earth; like free Star port, Colonizer, Transport. This support is same as the human player. 
 - Buy more spaceships & transporters for more exports if they have enough funds.
 - Buy more colonizers and build new colonies if they have enough funds.
 - Engineers are automated; they will build tile improvements around colonies and roads between them.
 - Complete missions whenever possible.
 - Have random events same as human player.
 - Have same national properties as human player.
* An order to destroy tile improvement(s) can be given to units. Scouts and engineers can destroy improvement of the tile they occupy in 1 turn. Following actions are possible :
 - Destroy all improvements
 - Destroy roads
 - Destroy irrigation
 - Destroy mine
* Engineer automating logic updated to build more roads when player has a "Build road" mission.
* Fertilizer removal bug fixed.
* Minor unit animation updates made.
* Pre-made map panel in new game wizard is updated to display selected map information.
* Suggested number of players warning added to new game wizard.
* Null centered coordinate after game load is fixed.
* Minimum prices of iron, silica and minerals are increased to 3 from 2.
* Transporter capacity increased to 5000 from 3000.
* Finance cost per colonist is set to 200 credits.
* Start coordinate generation logic is updated to allow some space between players.
* Transforming a tile will not remove roads; other tile improvements like irrigation and mines will still be removed.
* Map scrolling that is triggered by hovering mouse at the edges is added to Preferences; the default is off.
* Mouse wheel can be used to zoom and out in main map.
* About box dimensions updated.
* Game objects XML tag configuration updated.
* Bug #218 : "South pole camera scroll" is fixed.
* Bug #220 : "Unit count statistics y-axis data values are not visible if bigger than 2 digits" is fixed.
* Bug #219 : "Treasury statistics y-axis data values are not visible if bigger than 5 digits" is fixed.
* Updates in XML configuration of maps.
* Logging added.

Version 0.8.5.7 (June 10, 2014)
-----
* Engineer automation added.
* Missions' information updated. Objectives in mission text are written bold font. Amount information formatted.
* Some random event messages updated.
* Road images added.
* Image configuration updated.
* Colony manager bug caused by colonies that have 0 population is fixed.
* Mining accident event added.
* Ice tile type added to movable tile types of Engineer unit.
* Free financial aid dialog close bug fixed.
* Null pointer exception in colony dialog fixed.
* Logging added.

Version 0.8.5.6 (May 10, 2014)
-----
* This version fixes some major bugs in version 0.8.5.5.
* Colonists are auto assigned to hydrogen collectors at the beginning of the game.
* Bank improvement removed.
* Units with active orders and movement points bug fixed.
* XML formats updated.
* Enter key is assigned to "Buy" button in "Buy colony production" dialog.
* Colony improvement requirements bug fixed:
 - Steel works -> Steel factory
 - Glass works -> Glass factory
 - Chemical works -> Chemical plant
* Event images changed:
 - Shuttle accident
 - Transporter accident
 - Hydrogen explosion
* Unit order execution bug fixed.
* Build settlement improvement mission bug fixed.
* Logging added.

Version 0.8.5.5 (May 7, 2014)
-----
* This version is not compatible with saved game files of previous versions because of XML configuration changes for new colony improvements.
* New colony improvements & images added:
 - Steel works
 - Glass works
 - Chemical works
* Colony improvement requirements updated:
 - Steel works -> Steel factory
 - Glass works -> Glass factory
 - Chemical works -> Chemical plant
* Buy dialog is updated.
* "Buy" button is disabled in colony dialog if buying is not possible.
* Colony improvement upkeep costs are fixed to 1% of production price.
* Iron, silica and mineral output of hills and craters  is reduced by 1.
* Mine improvement on iron, silica and mineral resources is increased by 1.
* Silica production of desert tile type is increased to 3.
* New colonies auto use fertilizer.
* Food and water production will be updated for auto-managing colonies after a free colonists event.
* A confirmation dialog will appear if Earth dialog is being closed while there are idle spaceships in Earth orbit.
* Resources part reformatted in unit information panel.
* Tool tip added to improvements tab of the colonies manager dialog.
* When a spaceship is sold to Earth, any cargo on the vessel will also be sold.
* In colony dialog workforce management panel, right mouse button can be clicked to remove a workforce on a colony tile.
* Default auto save period is set to 5 turns.
* "Bug #211 - Infinite auto end turn when moveable unit on Earth." is fixed.
* Collect debris mission coordinates bug fixed.
* Colony rename image added to Colony dialog. Thanks Billy Venus :)
* Earth dialog ESC key close bug fixed.
* Colony manager fertilized tiles bug fixed.
* Unit manager dialog size set to 1200 x 700.
* Size of save game file is reduced.
* Some spelling errors in XML files corrected.
* Logging added.

Version 0.8.5.4 (April 19, 2014)
-----
* Collect debris mission added.
* Build colony improvement mission added.
* Missions dialog updated:
 - Size set to 1200 x 700.
 - Screen size check added.
 - Credit reward amount values are formatted.
 - Even rows are colored light gray.
* Following values are updated in Solar array colony improvement.
 - Production cost is lowered from 4000 to 2000.
 - Upkeep cost is lowered from 120 to 60.
 - Energy storage is increased from 90.000 to 100.000.
 - Energy output is lowered from 1.000 to 500.
* Rename menu item added to unit pop-up menu in main map.
* Unit images added to unit pop-up menu in main map.
* Rename menu item added to unit pop-up menu in colony dialog.
* "Disband unit" text changed to "Disband" in unit pop-up menu.
* Following images changed:
 - Hydrogen resource
 - Lumber resource
 - Minerals resource
 - Minerals bonus resource
 - Chemicals resource
 - Glass resource
* "Bug #205 - It is possible to build workshop after Factory is completed." is fixed.
* Marsopedia page about tile transformation process and required turns for each tile type added.
* Logging added.

Version 0.8.5.3 (March 25, 2014)
-----
* This version is not compatible with saved game files of previous versions because of an XML configuration change in colony improvements.
* Colony manager dialog updated to display detailed data. Following tabs added:
 - Growth
 - Production
 - Manufacturing
 - Resources
 - Improvements
 - Garrison
* Colony improvement info updated to display expected resource production and colonists assigned.
* Population increase interval values updated.
* Images added to colony dialog previous / next colony buttons. Thanks Billy Venus :)
* Colony improvement resource production XML format updated.
* Silica and mineral resources removed from wasteland tile type.
* Food output of wasteland is reduced to 4 from 6.
* Iron output of swamp is reduced to 1 from 3.
* Russian hydrogen usage bonus is updated to 50%. Russian spaceships use %50 less hydrogen in spaceflight.
* Finance cost per colonist is set to 150 credits.
* Some logging added.

Version 0.8.5.2 (March 7, 2014)
-----
* Workforce assign pop-up updated to allow custom number of colonists to be set to a tile as a work force.
* Input resource requirements and the produced resource of a colony improvement is shown on top of improvement image.
* Buttons added to colony dialog to display previous and next colony.
* A message will warn the player one turn before a resource will be wasted due to lack of storage.
* LGT unit image changed.
* Some logging added.
* Lumber resource price increased.
* Water requirement in Hydroponic farms is halved.
* Minor Marsopedia updates.
* Minor XML configuration file updates made.

Version 0.8.5.1 (February 19, 2014)
-----
* Mech unit image changed.
* A message indicating the foundation of a new colony is added. The message will be displayed if the colony is founded after a "Go to and ..." order.
* Transporter can move on hills and craters.
* Trade dialog size check added for screen resolution.
* Victory, Defeat and Demographics dialog widths are increased.
* Message history dialog order is reversed. Newest messages are displayed on top.
* Message history dialog width is increased.
* When a colony dialog is displayed, one of the units inside the colony that can carry cargo will be automatically selected.
* Resource drag & drop bug in colony panel is fixed.
* Food resource removed from desert tile type.
* Irrigation improvement removed from desert tile type.
* Path check added for "Go to coordinate" orders.
* Some logging added.
* Marsopedia unit images updated.

Version 0.8.5.0 (February 13, 2014)
-----
* Resource drag & drop in colony panel is modified to allow transfers between units and drops on unit images.
* Unit display bug at coordinates near 0 abscissa are fixed.
* Colony dialog size check added for screen resolution.
* Formatting update on demographics dialog.

Version 0.8.4.9 (February 6, 2014)
-----
* Victory, Defeat and Demographics dialogs are updated to display detailed data.
* Expeditionary force landing coordinate decision updated.
* Unit type count added to unit manager dialog.
* Some formatting done on dialogs.
* Missions are not assigned if player has declared independence.
* Declaration of independence will cancel current missions.
* Spaceship arrival message bug fixed. Unit name will be used in message, not type and id.
* Marsopedia broken image links fixed for resources.

Version 0.8.4.8 (January 12, 2014)
-----
* Expeditionary force landing coordinate decision updated.
* Earth government will seize spaceships that were traveling to or already in orbit of Earth after declaration of independence.
* Financing colonists from Earth is rejected after declaration of independence.
* Buying units from & selling units to Earth are rejected after declaration of independence.
* Buying resources from & selling resources to Earth are rejected after declaration of independence.
* Following random events are not possible after declaration of independence :
 - Free colonists
 - Credit donation
 - Fertilizer donation
* Magnesium output of mountains is reduced from 2 to 1.
* Mine improvement on Magnesium resource is increased from 0 to 1.
* Silica resource removed from Crater terrain type.
* Food auto management bug fixed.
* Transport carrying capacity increased to 3000 from 2000.
* Freighter carrying capacity increased to 8000 from 6000.
* Bulk freighter carrying capacity increased to 20000 from 10000.
* Colony dialog updated to enable mouse movement to select units that can carry cargo.
* Expeditionary force landing time after declaration of independence is increased to 8 turns.
* Version info added to About dialog.
* New random events added :
 - Water leak
 - Food contamination
 - Energy loss

Version 0.8.4.7 (December 22, 2013)
-----
* Colony dialog updated to enable mouse movement to select units.
* Messages dialog will be closed if there is a single message in it and users clicks to open message detail.
* "Unload all cargo" order added to "Go to this tile and..." sub menu.
* Bug #199 : "Unit manager error for units on board other units" is fixed.
* Bug #197 : "Enable / Disable colony improvements does not update available colonists for workforce." is fixed.
* Number values in the trade information are formatted.
* Level II mission reward is increased to 20.000 from 15.000.
* Level III mission reward is increased to 30.000 from 20.000.
* Earth dialog trade information amounts formatted.
* Earth tax rate reduced.

Version 0.8.4.6 (November 21, 2013)
-----
* In colony production queue dialog, tooltip text is added to units that are not currently buildable because prerequisites are not met.
* Mech production prerequisite bug fixed. Having a "Mech barracks" in a colony allows production of Mechs.
* Build cost for colonizer is decreased to 6.000 from 8.000. (Buy price from Earth is 34K credits)
* Transform tile added to unit pop-up menu.
* Go to coordinate and Transform tile added to unit pop-up menu.
* Number formatting added to Earth dialog unit prices.
* Colony tax help page added to Marsopedia. The page is displayed when F1 is pressed in Colony tax dialog.
* Ctrl+T shortcut added to display Colony tax dialog.
* Population prerequisite for steel factory is decreased to 200 from 250.
* Population prerequisite for glass factory is decreased to 250 from 300.
* Population prerequisites for shuttle, freighter and bulk freighter are reduced to 300, 350 and 400.

Version 0.8.4.5 (November 16, 2013)
-----
* Starting wealth is increased to 25.000 credits.
* Colonizer and transporter units are added to Earth unit buy list.
* Production point cost is increased to 4 credits.
* Level I mission reward is increased to 10.000 from 5.000.
* Level II mission reward is increased to 15.000 from 10.000.
* Level III mission reward is increased to 20.000 from 15.000.
* Shuttle build cost is increased to 10.000 production points.
* Shuttle buy cost is increased to 40.000 credits.
* Freighter build cost is increased to 20.000 production points.
* Freighter buy cost is increased to 80.000 credits.
* Bulk freighter build cost is increased to 30.000 production points.
* Bulk freighter buy cost is increased to 120.000 credits.
* Mech build cost is increased to 10.000 production points.
* Mech buy cost is increased to 40.000 credits.
* Starting wealth bonus for Australians is increased to 25.000 from 15.000.
* Marsopedia updates made.

Version 0.8.4.4 (November 5, 2013)
-----
* Map panel painting performance updates made.
* Colonists returning to Earth event added.
* Possibility of the following events are reduced :
 - Meteor strike
 - Oxygen leak
 - Fire
 - Hydrogen explosion
 - Transporter accident
 - Shuttle accident
* Population mission target values are changed to 400, 1200 and 3600.
* Colony count mission target values are changed to 4, 8 and 12.
* Ctrl + Q shortcut added to quit game.
* Minor shortcut updates made.
* Earth dialog unit selection buttons rearranged. Background color added to E.T.A times.
* Orbit dialog unit selection buttons rearranged. Background color added to E.T.A times.
* Orbit dialog image bug fixed.
* Free colonizer dialog image bug fixed.
* Free transporter dialog image bug fixed.
* Colony manager dialog image bug fixed.
* XML configuration updated.
* Marsopedia updated.

Version 0.8.4.3 (October 26, 2013)
-----
* In unit manager dialog, clicking on a unit will select it and focus map panel to that unit's coordinate.
* Pop-up menu added to give orders to units from unit manager dialog.
* Free Mars icon changed.
* Free Mars frame image changed.
* Unit details panel null coordinate bug fixed.
* Unload cargo for unit null coordinate bug fixed.

Version 0.8.4.2 (October 19, 2013)
-----
* Unit manager dialog added.
* Shuttle, freighter and bulk freighter unit images changed.
* Menu shortcuts updated.
* Marsopedia updated.

Version 0.8.4.1 (October 9, 2013)
-----
* Name added to units.
* Unit rename shortcut (CTRL + R), menu item added.
* Spacecraft can be renamed in orbit and earth dialogs.
* Image scaling bug for units solved.

Version 0.8.4.0 (September 29, 2013)
-----
* Auto end turn added.
* Colors of the resource production and assigned colonists values changed in colony workforce panel.
* Marsopedia pages on vegetation is updated.
* Minor logging updates made.
* Save file format updated.
* Bugs fixed in colony workforce management panel painting.
* Added "Help" button to colony dialog.
* Assigned F1 key in colony dialog to display help.
* Added "Preferences" button to main menu.
* Added a Linux script (InstallFreeMars.sh) to launch installer.
* Moved colony improvement image configuration to a separate file.
* Added new tips to help pages.

Version 0.8.3.9 (September 15, 2013)
-----
* Multi directional units added. Units now face the direction they are moving.
* images.xml configuration file is separated to different files like tileImages.xml, unitImages.xml.
* Added vertical scrollbars to "Traveling to Mars" and "Traveling to Earth" parts of Earth dialog.
* Added vertical scrollbars to "Traveling to Mars" and "Traveling to Earth" parts of Mars orbit dialog.
* "Build colony" added to RMB menu of colonizer.
* Added bonus resources to random created maps.
* Added vegetation to random created maps.
* Fixed colony name painting bug in colony dialog workforce management panel.
* Fixed vegetation painting bug in colony dialog workforce management panel.

Version 0.8.3.8 (September 4, 2013)
-----
* Updated built in maps.
* Updated map rendering to display vegetation image variations.
* Vegetation is painted as a new layer above terrain.
* Tile improvements are painted as a new layer above terrain.

Version 0.8.3.7 (August 24, 2013)
-----
* Added shortcut creation DLL (ShellLink_x64.dll) for Win 7 to installer.
* Removed black lines that were seen between tiles when zoomed in.
* Population prerequisite for steel factory has been lowered to 250.
* Small, medium, large and huge maps are updated to have random images for all tile types.
* Small Marsopedia update.
* Following images changed:
 - Main menu background
 - Mutated cactus forest, Martian scrub forest vegetation
 - Ice, swamp and tundra terrain variations
 - Colonizer, transporter units

Version 0.8.3.6 (August 17, 2013)
-----
* Full screen option in preferences dialog is activated.
* Updated map panel to display different images  for the same tile type. 3 images added for swamp tile type.
* Small, medium, large and huge maps are updated to have random images for swamp tile type.
* Small Marsopedia update.
* Moved help pages to a separate library.
* Following images changed:
 - Scout unit
 - Giant mushrooms vegetation
 - Colony images 0, 1 and 2
 - Irrigation and mine tile improvements
 - Hills, mountains and misty mountains tile types

Version 0.8.3.5 (August 10, 2013)
-----
* A colony screen section is added to Marsopedia explaining sub parts of the colony management screen like resource production or unit cargo.
* "Exploration mission completed" and "Exploration mission failed" dialog bugs fixed.
* Population prerequisite for colonizer unit type is reduced to 200 colonists.
* Starting wealth bonus for Australians is increased to 15.000 from 10.000.
* Decoration images added to mini-map and unit details/end turn panels.
* Fixed the text overlapping bug. Tile coordinate and tile type information are displayed in 2 lines.
* Updates in "BuildTileImprovement" property logic.
* Format updates in configuration files.
* Wasteland, desert and tundra tile, Martian taiga vegetation images changed.

Version 0.8.3.4 (August 3, 2013)
-----
* Exploration mission target is set to tile count, not percent of the map. This makes mission difficulty same in all map sizes.
* "Display unit move animation" option is added to preferences dialog.
* Following orders added to engineer menu
 - Build roads & irrigation (on current tile)
 - Build roads & mine (on current tile)
 - "Go to this tile (X, Y) and build roads & irrigation"
 - "Go to this tile (X, Y) and build roads & mine"
* Population change logic updated
 - Seperated population increase and decrease
 - Configuration is read from XML file
 - Floating point values allowed for percent changes
* Number of required colonists population missions are set to 500, 1500 and 4500
* National property added to Brazilians. They start the game with 3 colonizers.
* Fixed bugs in preferences dialog and related preferences save file.

Version 0.8.3.3 (July 21, 2013)
-----
* Random events added. Following random events can happen each turn:
 - Meteor strike
 - Oxygen leak
 - Hydrogen explosion
 - Fire
 - Transporter accident
 - Shuttle accident
 - Free colonists
 - Credit donation
 - Fertilizer donation
* Send to Earth menu item added to map unit popup menu.
* If a colony tile can produce more than 5 units of a resource it is displayed with a single image and a multiplier.
* Cargo transfer sound added.
* Bulk freighter unit image changed.
* Freighter unit image changed.

Version 0.8.3.2 (June 23, 2013)
-----
* Spaceship launch sound added.
* Cargo capacity bonus added to Swedish units. They can carry %25 more cargo compared to units of other nations.
* Small Mars map updated. More vegetation and hills added.
* Free Mars frame image changed.
* Scout unit image changed.
* Bulk freighter unit image changed.
* Unit resources panel updated. 2px empty area added to the top of each resource quantity image.
* Total tax paid property added to player demographics dialog.
* Tax paid info for each resource is added to trade data dialog.
* Open premade map dialog's default directory is set to Free Mars directory.
* National properties tool tip text formatted.
* Fertilizer usage for a tile per turn is decreased from 50 to 25.
* Fertilizer usage is displayed as "-" in colony resources table in colony dialog.

Version 0.8.3.1 (June 13, 2013)
-----
* Spaceship construction prerequisite bug fixed.
* Lowered Earth tax increase rate.
* Lowered Fertilizer sell price.

Version 0.8.3.0 (June 9, 2013)
-----
* Victory dialog added with "Continue game" and "Return to main menu" options.
* Free Mars game icon changed.
* Maximum colonists per tile bonus added to Polish (ModifyMaximumWorkers property).
* Starting wealth bonus of 10.000 credits added to Australians (ModifyStartingWealth property).
* Solar panel energy output increased to 250.
* Solar array energy output increased to 1000.
* Transporter image changed.
* Price for selling energy to Earth is fixed at 1.
* Resource carrier units in a colony now displays only the resources it is currently carrying.
* Earth financial aid added. Player will receive a free financial aid after 60 turns.
* Earth prices changed for fertilizer resource.
* Save game XML file bugs fixed.

Version 0.8.2.9 (May 26, 2013)
-----
* Fertilizer usage added to increase food production in colonies.
* Colony improvement upgrades added.
* Solar panel upgrades to Solar array.
* Water pump upgrades to Water extractor.
* Granary upgrades to Food silo.
* Unload colonists popup in colony dialog is updated.
* When colonists are unloaded in a colony, automanage water and food is performed.
* AutoSave file names changed, human player name added.
* Remaining turns for unit orders in colonies are displayed.
* Steel factory, glass factory and chemical plant input resource bug fixed.

Version 0.8.2.8 (April 27, 2013)
-----
* Earth tax is added.
* Earth tax statistics added.
* Nation properties added for Spanish, Indians, Russians, Japanese, Italians, Koreans, Turks.
* Unit color rectangle width bug fixed for orders taking more than 10 turns to complete.
* Expeditionay force update is displayed as a player message line, not as popup.

Version 0.8.2.7 (March 12, 2013)
-----
* Nation properties added for English, French, Germans, Americans and Chinese.
* Automanaging option for water and food added to colony dialog.
* Build road, irrigation, mine improvements are disabled if a unit has no movement points left.
* Build colony is disabled if a unit has no movement points left.
* Ctrl+N shortcut added for starting a new game.

Version 0.8.2.6 (February 14, 2013)
-----
* Terrain transformation order added, a tile's type can be changed with this order.
* Selling a unit to Earth is now possible.
* Free Mars map editor tile bonus resource selection updated, "None" is added.
* More vegetation added to Mars small map.
* Roads increase iron, silica and mineral output.
* Leather and Coats resources are replaced with Water and Fertilizer.
* Water is required for colony growth.
* Water resource production column is added to colony management table.
* Each colony receives 1000 water when built.
* Updates on XML formats of tile types.

Version 0.8.2.5 (January 13, 2013)
-----
* Logging added using "log4j".
* Player defeat checks and defeat dialog added.
* Messages added for AI player defeats.
* Secondary color added to player.
* Secondary color is used in painting colony names, unit order information etc.
* Save game bug fixed.
* Vegetation clear bug fixed. Now lumber is also added to settlement on cleared tile.
* Remaining turns added to missions dialog.
* Next production info is added to colony production completed message.
* "Unload all cargo" is added to unit orders popup menu.
* Updates made on colony improvements.
* Updates made on units.
* Smoother unit movements on map.

Version 0.8.2.4 (December 22, 2012)
-----
* Attack confirmation dialog added.
* Messages added for unit battles and colony capture.
* Shortcut letters displayed in game menu.

Version 0.8.2.3 (December 4, 2012)
-----
* Expeditionary force enhancements made.
* Expeditionary force now displays remaining expeditionary force units, not starting values.
* Tile bonus resource is also displayed if active unit is on such a tile.
* Buy colony production dialog displays credits needed to buy selected amount of production.
* Exploration statistics bug fixed.
* Statistics dialog X-axis bug fixed.
* Earth unit prices changed.
* Unload all cargo unit command added.
* Shortcut letters displayed in game menu.

Version 0.8.2.2 (November 19, 2012)
-----
* Links from message boxes to related dialogs added added.
* Colony dialog unit and improvement size bug fixed.
* "Continue game" button added to main menu.

Version 0.8.2.1 (November 3, 2012)
-----
* More work done on missions.
* Marsopedia updates made.

Version 0.8.2.0 (October 30, 2012)
-----
* Expeditionary force player & related AI added.
* Expeditionary force dialogs added.
* Next unit activation on 0 movement points bug fixed.
* More work on missions.
* Updates on upkeep costs of colony improvements.
* New nations added.

Version 0.8.1.9 (September 27, 2012)
-----
* When a vegetation on a tile is cleared 500 lumber is added to colony.
* Nation flag images added to new game wizard player selection panel.
* Wealth label bug for great values fixed.
* Free hydrogen collectors are only added to first two colonies now, not all.
* F4 shortcut added to display trade data.
* F5 shortcut added to diplomacy dialog.
* More work done on missions.

Version 0.8.1.8 (September 22, 2012)
-----
* More work on missions.
* Marsopedia updates.

Version 0.8.1.7 (September 3, 2012)
-----
* Unit movement animation added.
* Expiration date added to missions.
* F3 shortcut added to display mission manager.
* Mission explanation text fixes.

Version 0.8.1.6 (August 18, 2012)
-----
* 5 Player missions added.
 - Exploration mission x 2
 - Population mission x 2
 - Export resource mission

Version 0.8.1.5 (August 2, 2012)
-----
* Player missions added using infrastructure in FreeRealm framework.

Version 0.8.1.4 (July 12, 2012)
-----
* Fixed Colony improvement workers save bug.
* Output resource quantity and image added to colony improvement.
* Added bonus resources to medium, large and huge maps.
* Editor resize dialog opens with current map's height & width.
* Marsopedia updates.

Version 0.8.1.3 (July 5, 2012)
-----
* Added colony improvement workers.
* Changed game folder to "user directory" + FreeMars.

Version 0.8.1.2 (June 1, 2012)
-----
* Added tile bonus resources.
* Added new help pages.

Version 0.8.1.1 (April 27, 2012)
-----
* Added shortcut page to installer.
* Fixed colony name XML problems.
* Ctrl + S and Ctrl + L shortcuts added.
* F1 shortcut added.

Version 0.8.1.0 (April 4, 2012)
-----
* Unit sight radius bug fixed.
* Marsopedia updates.

Version 0.8.0.9 (February 25, 2012)
-----
* Scout has 2 tiles sight radius.
* Unit sight radius property added.

Version 0.8.0.8 (February 14, 2012)
-----
* Unit pathfinding bug fixed.
* Updated Marsopedia pages.
* Save XML format updates made.

Version 0.8.0.7 (February 2, 2012)
-----
* F8/F9 shortcuts added for quick save and quick load.
* Display Earth and Mars orbit shortcuts and buttons added.
* Marsopedia updates.
* Save XML format updates.

Version 0.8.0.6 (January 12, 2012)
-----
* Marsopedia button added to main menu.
* Marsopedia updates.
* Save XML file encoding bug fixed.
* Earth prices logic changed.

Version 0.8.0.5 (December 2, 2011)
-----
* Spaceship travel bugs fixed.
* Display Earth and Mars orbit added.
* Earth trade added.

Version 0.8.0.4 (November 19, 2011)
-----
* Bulk freighter unit added.
* Marsopedia update for bulk freighter unit.

Version 0.8.0.3 (November 15, 2011)
-----
* Freighter unit added.
* Marsopedia updated for freighter unit.

Version 0.8.0.2 (November 12, 2011)
-----
* Spaceship travel between Mars, Mars orbit and Earth added.
* Shuttle unit added.
* Marsopedia updated for shuttle unit.

Version 0.8.0.1 (November 5, 2011)
-----
* Minor unit type updates made.
* Minor Marsopedia updates made.

Version 0.8.0.0 (November 2, 2011)
-----
* Unit weight property added for cargo.

Version 0.7.9.9 (October 29, 2011)
-----
* Population carry bug fixed.
* Tile images updated.
* Neighbor tile images updated.

Version 0.7.9.8 (October 27, 2011)
-----
* Unit cargo property updated to carry population.
* Earth dialog is updated to allow spaceships to carry colonists.
* Save XML format changes.

Version 0.7.9.7 (October 25, 2011)
-----
* Unit cargo property updated to carry other units.
* Earth dialog is updated to allow spaceships to carry other units.
* Save XML format changes.

Version 0.7.9.6 (October 24, 2011)
-----
* Unit cargo weight property added.
* Minor Marsopedia updates made.
* Neighbor tile images updated.

Version 0.7.9.5 (October 21, 2011)
-----
* Unit cargo property added.
* XML format updates made.

Version 0.7.9.4 (October 11, 2011)
-----
* Installer updates.
* Fixes made in new game wizard.

Version 0.7.9.3 (October 7, 2011)
-----
* Mineral resource updated.
* Updated Marsopedia for resources.
* Updated images for resources.
* Made small updates on neighbor tile images.

Version 0.7.9.2 (October 4, 2011)
-----
* Stone removed from extractable resources XML.
* Gas removed from extractable resources XML.
* Updated Marsopedia for resources.
* Updated images for resources.
* Neighbor tile images added.

Version 0.7.9.1 (October 1, 2011)
-----
* Colonizer image changed.
* Engineer image changed.
* Resource XML configuration file format updates.

Version 0.7.9.0 (September 28, 2011)
-----
* Chemicals resource added.
* Chemical plant colony improvement added to be used with mineral resource.
* Marsopedia updated for chemical plant.
* Colony improvement configuration XML updates for input and output resources.

Version 0.7.8.9 (September 26, 2011)
-----
* Mineral resource added.
* Resource XML configuration file changed.
* Marsopedia updates made.

Version 0.7.8.8 (September 25, 2011)
-----
* Dummy resources like stone, gas removed.
* Resource XML configuration file changed.
* Mine tile improvement properties updated.

Version 0.7.8.7 (September 22, 2011)
-----
* Major updates in colony management panel.
* Save XML format updates made.
* Marsopedia updates made.

Version 0.7.8.6 (September 12, 2011)
-----
* Colonies management list bugs fixed.
* Irrigation tile improvement properties updated.

Version 0.7.8.5 (September 10, 2011)
-----
* Colonies management list bugs fixed.
* Marsopedia updates made.
* Stone resource image changed.
* Resource XML configuration file changed.

Version 0.7.8.4 (September 5, 2011)
-----
* Colonies management list added.
* Marsopedia updated.
* Soldier unit removed.

Version 0.7.8.3 (August 28, 2011)
-----
* Added mine tile improvement.
* Marsopedia updated.

Version 0.7.8.2 (August 25, 2011)
-----
* Added irrigation tile improvement.
* Marsopedia updated.

Version 0.7.8.1 (August 20, 2011)
-----
* Added tile improvements structure to modify tiles.
* Added roads.
* Marsopedia updated.
* XML configuration file for tile improvements added.

Version 0.7.8.0 (August 17, 2011)
-----
* Movement point modifier property added to game.
* Tax modifier property updated.
* XML configuration file for properties updated.

Version 0.7.7.9 (August 15, 2011)
-----
* Production point modifier property added to game.
* Tax modifier property added.
* XML configuration file for properties updated.

0.7.7.8 - 0.7.5.0 Previous development versions