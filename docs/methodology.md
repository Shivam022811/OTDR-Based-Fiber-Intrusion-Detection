## Methodology

### 1. System Setup

A single-mode optical fiber was wrapped around the door hinge to act as a bend-loss sensor. As the door rotates, the bend radius of the fiber changes, resulting in variations in optical attenuation.

### 2. Optical Sensing and OTDR Analysis

Light was transmitted through the optical fiber, and attenuation caused by fiber bending was monitored. OTDR measurements were utilized to analyze optical losses and identify the location of disturbances along the fiber link.

### 3. Regional Wind Modeling

The system incorporated representative wind force values for four Indian regions:

* Western Coastal Region
* Eastern Himalayan Foothills
* North Indian Plains
* Deccan Plateau

These wind forces were considered as environmental inputs affecting door movement.

### 4. Force Acquisition and Processing

Additional forces representing human and animal interactions were applied to the system. The Arduino platform processed the force inputs and combined them with regional wind effects to determine the total force acting on the door.

### 5. Door Angle Estimation

Using rotational motion principles, the total force was converted into door deflection angle. The estimated angle was used to determine the degree of door movement and corresponding fiber bend radius.

### 6. Bend Loss Calculation

The change in bend radius produced optical attenuation in the fiber. The relationship between bend radius, optical loss, and door angle was analyzed to establish a sensing model for intrusion detection.

### 7. Entity Classification

The calculated force values were compared against predefined thresholds to classify the probable source of door movement, including:

* Cow
* Goat
* Dog
* Cat
* Adult
* Child
* Elderly Person

### 8. Result Generation

The system displayed:

* Region and wind condition
* Applied force
* Estimated door angle
* Optical loss characteristics
* Identified entity type

The results were validated through simulation and experimental testing under multiple environmental and intrusion scenarios.

