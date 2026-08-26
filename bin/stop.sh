#! /bin/bash

ps aux | grep home| grep vs | grep darkeden  | grep server | grep -v "test" | grep -v "grep" | awk '{print $2}' | xargs kill
